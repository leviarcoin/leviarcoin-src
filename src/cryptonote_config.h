// Copyright (c) 2014-2018, The Monero Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS                             20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                           500000000
#define CRYPTONOTE_MAX_BLOCK_SIZE                             500000000  // block header blob limit, never used!
#define CRYPTONOTE_GETBLOCKTEMPLATE_MAX_BLOCK_SIZE	          196608 //size of block (bytes) that is the maximum that miners will produce
#define CRYPTONOTE_MAX_TX_SIZE                                1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER                0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW                  60
#define CURRENT_TRANSACTION_VERSION                           2
#define CURRENT_BLOCK_MAJOR_VERSION                           1
#define CURRENT_BLOCK_MINOR_VERSION                           0
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT                    60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE                   10

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW                     60

// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                          UINT64_C(5400000000000000)
#define GENESIS_BLOCK_REWARD                                  UINT64_C(810000000000000)
#define EMISSION_SPEED_FACTOR_PER_MINUTE                      (22)
#define FINAL_SUBSIDY_PER_MINUTE                              ((uint64_t)30000000) // 3 * pow(10, 7)
#define CRYPTONOTE_MAX_BLOCK_NUMBER                           500000000
#define UPGRADE_HEIGHT_V1                                     uint32_t(250000)
#define UPGRADE_HEIGHT_V2                                     uint32_t(325000)
#define UPGRADE_HEIGHT_V3                                     uint32_t(337000)
#define UPGRADE_HEIGHT_V4                                     uint32_t(493500)
#define UPGRADE_HEIGHT_V5                                     uint32_t(586000)
#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                       size_t(100)
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE             size_t(1000000) //size of block (bytes) after which reward for block calculated using block size
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1          size_t(20000)
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2          size_t(200000)
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2_ALT      60000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT     CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5          300000

#define MAX_BLOCK_SIZE_INITIAL                                ((size_t)20 * 1024)
#define MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR                 ((uint64_t)500 * 1024)
#define MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR_V1              ((uint64_t)100 * 1024)
#define MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR               ((uint64_t)365 * 24 * 60 * 60 / DIFFICULTY_TARGET_V1)

#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE                600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                      8
// COIN - number of smallest units in one coin
#define COIN                                                  ((uint64_t)100000000) // pow(10, 8)

#define FEE_PER_KB_OLD                                        ((uint64_t)1000000) // pow(10, 6)
#define FEE_PER_KB                                            ((uint64_t)200000) // 2 * pow(10, 5)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                           ((uint64_t)200000) // 4 * pow(10, 5)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD                  ((uint64_t)1000000000) // 10 * pow(10,8)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V5                        ((uint64_t)400000 * (uint64_t)CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2_ALT / CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V7                        (uint64_t)40000

#define ORPHANED_BLOCKS_MAX_COUNT                             100


//#define DIFFICULTY_TARGET_V2                            120  // seconds
#define DIFFICULTY_TARGET_V2                                  60  // seconds
#define DIFFICULTY_TARGET_V1                                  60  // seconds - before first fork
#define DIFFICULTY_TARGET                                     60  // seconds - before first fork
#define DIFFICULTY_WINDOW                                     24 * 60  // blocks
#define DIFFICULTY_LAG                                        15  // !!!
#define DIFFICULTY_CUT                                        60  // timestamps to cut after sorting
#define DIFFICULTY_BLOCKS_COUNT                               DIFFICULTY_WINDOW + DIFFICULTY_LAG


#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V1         DIFFICULTY_TARGET_V1 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V2         DIFFICULTY_TARGET_V2 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS             1


#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN                   DIFFICULTY_TARGET_V1 //just alias; used by tests


#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT                10000  //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT_PRE_V4             100    //by default, blocks count in blocks downloading
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT                    20     //by default, blocks count in blocks downloading

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                        (86400*1) //seconds, one day
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME         604800 //seconds, one week

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT                 1000

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                        1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                         5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                         8
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                        60           //secondes
#define P2P_DEFAULT_PACKET_MAX_SIZE                           50000000     //50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                        250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                        5000       //5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT                   2000       //2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                            60*2*1000  //2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT                  5000       //5 seconds
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT             70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT                  2

#define P2P_FAILED_ADDR_FORGET_SECONDS                        (60*60)     //1 hour
#define P2P_IP_BLOCKTIME                                      (60*60*24)  //24 hour
#define P2P_IP_FAILS_BEFORE_BLOCK                             10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL                     (5*60) //5 minutes

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                        0//0x01
#define P2P_SUPPORT_FLAGS                                     P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define ALLOW_DEBUG_COMMANDS

#define CRYPTONOTE_NAME                                       "leviar"
#define CRYPTONOTE_POOLDATA_FILENAME                          "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME                    "data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME               "lock.mdb"
#define P2P_NET_DATA_FILENAME                                 "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                                "miner_conf.json"

#define THREAD_STACK_SIZE                                     5 * 1024 * 1024

#define HF_VERSION_DYNAMIC_FEE                                4
#define HF_VERSION_MIN_MIXIN_4                                6
#define HF_VERSION_MIN_MIXIN_6                                7
#define HF_VERSION_ENFORCE_RCT                                6

#define PER_KB_FEE_QUANTIZATION_DECIMALS                      8

#define HASH_OF_HASHES_STEP                                   256

#define DEFAULT_TXPOOL_MAX_SIZE                               648000000ull // 3 days at 300000, in bytes

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 500; // Just a placeholder!  Change me!
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)200000); // pow(10, 6)
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)10000); // pow(10, 4)
  //std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115";
  std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "0000000000000000000000000000000000000000000000000000000000000000";

  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x76; // addresses start with "L"
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x77; // addresses start with "M"
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x78; // addresses start with "N"
  uint16_t const P2P_DEFAULT_PORT = 18001;
  uint16_t const RPC_DEFAULT_PORT = 19001;
  uint16_t const DRM_NETWORK_DEFAULT_PORT = 19002;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 19003;
  boost::uuids::uuid const NETWORK_ID = { {
      0x65, 0xa9, 0x92, 0x2e, 0xf9, 0x0c, 0x2a, 0x34, 0x6b, 0x4d, 0xc2, 0xcb, 0x1c, 0xd2, 0x52, 0x10
  } };
  std::string const GENESIS_TX = "013c01ff000180c092928d96b801029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210104bbb5fb59c2c9c7f474ba938323e1ebc0c1dcd4216769e2626b9f7638a784e2";
  uint32_t const GENESIS_NONCE = 70;

  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x79; // addresses start with "O"
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x7A; // addresses start with "P"
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x7B; // addresses start with "Q"
    uint16_t const P2P_DEFAULT_PORT = 28001;
    uint16_t const RPC_DEFAULT_PORT = 29001;
    uint16_t const DRM_NETWORK_DEFAULT_PORT = 29002;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 28003;
    boost::uuids::uuid const NETWORK_ID = { {
        0x66, 0xaa, 0x93, 0x2f, 0xfa, 0x0d, 0x2b, 0x35, 0x6c, 0x4e, 0xc3, 0xcc, 0x1d, 0xd3, 0x53, 0x11
      } };
    std::string const GENESIS_TX = "013c01ff000180c092928d96b801029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210104bbb5fb59c2c9c7f474ba938323e1ebc0c1dcd4216769e2626b9f7638a784e2";
    uint32_t const GENESIS_NONCE = 71;
  }

  namespace stagenet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x7C; // addresses start with "R"
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x7D; // addresses start with "S"
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x7E; // addresses start with "T"
    uint16_t const P2P_DEFAULT_PORT = 38001;
    uint16_t const RPC_DEFAULT_PORT = 39001;
    uint16_t const DRM_NETWORK_DEFAULT_PORT = 39002;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 38003;
    boost::uuids::uuid const NETWORK_ID = { {
        0x66, 0xaa, 0x93, 0x2f, 0xfa, 0x0d, 0x2b, 0x35, 0x6c, 0x4e, 0xc3, 0xcc, 0x1d, 0xd3, 0x53, 0x11
      } };
    std::string const GENESIS_TX = "013c01ff000180c092928d96b801029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210104bbb5fb59c2c9c7f474ba938323e1ebc0c1dcd4216769e2626b9f7638a784e2";
    uint32_t const GENESIS_NONCE = 72;
  }
}

namespace cryptonote
{
  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
}
