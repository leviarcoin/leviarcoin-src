// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
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

#include <vector>

#include "gtest/gtest.h"

#include "CryptoNoteCore/CryptoNoteBasic.h"
#include "CryptoNoteCore/UpgradeDetector.h"

#include "Logging/ConsoleLogger.h"

namespace {
  using CryptoNote::BLOCK_MAJOR_VERSION_1;
  using CryptoNote::BLOCK_MINOR_VERSION_0;

  struct BlockEx {
    CryptoNote::BlockTemplate bl;
  };

  typedef std::vector<BlockEx> BlockVector;
  typedef CryptoNote::BasicUpgradeDetector<BlockVector> UpgradeDetector;

  class UpgradeTest : public ::testing::Test {
  public:

    CryptoNote::Currency createCurrency(uint32_t upgradeHeight = UpgradeDetector::UNDEF_HEIGHT) {
      CryptoNote::CurrencyBuilder currencyBuilder(logger);
      currencyBuilder.upgradeVotingThreshold(90);
      currencyBuilder.upgradeVotingWindow(720);
      currencyBuilder.upgradeWindow(720);
      currencyBuilder.upgradeHeightV2(upgradeHeight);
      currencyBuilder.upgradeHeightV3(CryptoNote::UpgradeDetectorBase::UNDEF_HEIGHT);
      return currencyBuilder.currency();
    }

  protected:

    Logging::ConsoleLogger logger;
  };

  class UpgradeDetector_voting_init : public UpgradeTest {};
  class UpgradeDetector_upgradeHeight_init : public UpgradeTest {};
  class UpgradeDetector_voting : public UpgradeTest {};

  void createBlocks(BlockVector& blockchain, size_t count, uint8_t majorVersion, uint8_t minorVersion) {
    for (size_t i = 0; i < count; ++i) {
      BlockEx b;
      b.bl.majorVersion = majorVersion;
      b.bl.minorVersion = minorVersion;
      b.bl.timestamp = 0;
      blockchain.push_back(b);
    }
  }

  void createBlocks(BlockVector& blockchain, UpgradeDetector& upgradeDetector, size_t count, uint8_t majorVersion, uint8_t minorVersion) {
    for (size_t i = 0; i < count; ++i) {
      BlockEx b;
      b.bl.majorVersion = majorVersion;
      b.bl.minorVersion = minorVersion;
      b.bl.timestamp = 0;
      blockchain.push_back(b);
      upgradeDetector.blockPushed();
    }
  }

  void popBlocks(BlockVector& blockchain, UpgradeDetector& upgradeDetector, size_t count) {
    for (size_t i = 0; i < count; ++i) {
      blockchain.pop_back();
      upgradeDetector.blockPopped();
    }
  }
}
