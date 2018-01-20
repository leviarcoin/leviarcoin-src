// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, Leviar developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <fstream>
#include <condition_variable>
#include <future>
#include <memory>
#include <mutex>

#include <boost/program_options/variables_map.hpp>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <boost/filesystem.hpp>

#include "IWalletLegacy.h"

#include "Common/ConsoleHandler.h"
#include "CryptoNoteCore/CryptoNoteBasicImpl.h"
#include "CryptoNoteCore/Currency.h"
#include "NodeRpcProxy/NodeRpcProxy.h"

#include <Logging/LoggerRef.h>
#include <Logging/LoggerManager.h>

#include <System/Dispatcher.h>

namespace CryptoNote
{
  /************************************************************************/
  /*                                                                      */
  /************************************************************************/
  class mini_wallet : public CryptoNote::INodeObserver, public CryptoNote::IWalletLegacyObserver, public CryptoNote::INodeRpcProxyObserver {
  public:
    mini_wallet(System::Dispatcher& dispatcher, const CryptoNote::Currency& currency, Logging::LoggerManager& log);

    bool init(const boost::program_options::variables_map& vm);
    bool deinit();
    bool run();
    void stop();

    const CryptoNote::Currency& currency() const { return m_currency; }

	std::string getWalletFile();
	std::string getWalletAddress();
	std::string getBalance();
	size_t getTxsCount();
	std::string getTxs();
	std::string transferWrapper(const std::vector<std::string> &args);
	bool resetWrapper();
	bool saveWrapper(std::string m_walletFilename);

  private:
	
  	bool openOutputFileStream(const std::string& filename, std::ofstream& file);
	std::error_code walletSaveWrapper(IWalletLegacy& wallet, std::ofstream& file, bool saveDetailes, bool saveCache);

    Logging::LoggerMessage success_msg_writer(bool color = false) {
      return logger(Logging::INFO, color ? Logging::GREEN : Logging::DEFAULT);
    }

    Logging::LoggerMessage fail_msg_writer() const {
      auto msg = logger(Logging::ERROR, Logging::BRIGHT_RED);
      msg << "Error: ";
      return msg;
    }

	void handle_command_line(const boost::program_options::variables_map& vm);

    bool new_wallet(const std::string &wallet_file, const std::string& password);
    bool close_wallet();

    bool show_incoming_transfers(const std::vector<std::string> &args);
    std::string transferGui(const std::vector<std::string> &args);
    bool reset(const std::vector<std::string> &args);
	
    //---------------- IWalletLegacyObserver -------------------------
    virtual void initCompleted(std::error_code result) override;
    virtual void externalTransactionCreated(CryptoNote::TransactionId transactionId) override;
    virtual void synchronizationCompleted(std::error_code result) override;
    virtual void synchronizationProgressUpdated(uint32_t current, uint32_t total) override;
    //-------------f---------------------------------------------

    friend class 
		_progress_reporter_t;

    class refresh_progress_reporter_t
    {
    public:
      refresh_progress_reporter_t(CryptoNote::mini_wallet& mini_wallet)
        : m_mini_wallet(mini_wallet)
        , m_blockchain_height(0)
        , m_blockchain_height_update_time()
        , m_print_time()
      {
      }

      void update(uint64_t height, bool force = false)
      {
        auto current_time = std::chrono::system_clock::now();
		if (std::chrono::seconds(m_mini_wallet.currency().difficultyTarget() / 2) < current_time - m_blockchain_height_update_time ||
            m_blockchain_height <= height) {
          update_blockchain_height();
          m_blockchain_height = (std::max)(m_blockchain_height, height);
        }

        if (std::chrono::milliseconds(1) < current_time - m_print_time || force) {
          std::cout << "Height " << height << " of " << m_blockchain_height << '\r';
          m_print_time = current_time;

		  std::string file_name_reset = m_mini_wallet.getWalletFile() + ".reset_";
		  boost::system::error_code ignore;
		  if (boost::filesystem::exists(file_name_reset, ignore)) {
			  // if exists write height
			  std::ofstream file_stream_reset;
			  if (!file_stream_reset.is_open()) file_stream_reset.open(file_name_reset);
			  file_stream_reset << height << "|" << m_blockchain_height;
			  file_stream_reset.flush();
			  file_stream_reset.close();

			  // Remove .reset_ file
			  if (height == m_blockchain_height) boost::filesystem::remove(file_name_reset);
		  }
        }
      }

    private:
      void update_blockchain_height()
      {
        uint64_t blockchain_height = m_mini_wallet.m_node->getLastLocalBlockHeight();
        m_blockchain_height = blockchain_height;
        m_blockchain_height_update_time = std::chrono::system_clock::now();
      }

    private:
      CryptoNote::mini_wallet& m_mini_wallet;
      uint64_t m_blockchain_height;
      std::chrono::system_clock::time_point m_blockchain_height_update_time;
      std::chrono::system_clock::time_point m_print_time;
    };

  private:
    std::string m_wallet_file_arg;
	std::string m_pwd_arg;
    std::string m_generate_new;
    std::string m_import_path;

    std::string m_daemon_address;
    std::string m_daemon_host;
    uint16_t m_daemon_port;
	std::string m_wallet_file_gui;

    std::string m_wallet_file;

    std::unique_ptr<std::promise<std::error_code>> m_initResultPromise;

    Common::ConsoleHandler m_consoleHandler;
    const CryptoNote::Currency& m_currency;
    Logging::LoggerManager& logManager;
    System::Dispatcher& m_dispatcher;
    Logging::LoggerRef logger;

    std::unique_ptr<CryptoNote::NodeRpcProxy> m_node;
    std::unique_ptr<CryptoNote::IWalletLegacy> m_wallet;
    refresh_progress_reporter_t m_refresh_progress_reporter;

    bool m_walletSynchronized;
    std::mutex m_walletSynchronizedMutex;
    std::condition_variable m_walletSynchronizedCV;

  };
}
