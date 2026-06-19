// Copyright (c) 2014-2022, The Monero Project
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

#include "hardforks.h"

#undef nethxeum_DEFAULT_LOG_CATEGORY
#define nethxeum_DEFAULT_LOG_CATEGORY "blockchain.hardforks"

const hardfork_t mainnet_hard_forks[] = {
  // Nethxeum: fresh chain launched May 31, 2026. All protocol upgrades active from genesis.
  // v1: genesis
  { 1,  1,  0, 1748649600 },
  // v2: CryptoNote improvements
  { 2,  2,  0, 1748649601 },
  // v3: bulletproofs preparation
  { 3,  3,  0, 1748649602 },
  // v4: RingCT mandatory, dynamic fee
  { 4,  4,  0, 1748649603 },
  // v5: larger block median
  { 5,  5,  0, 1748649604 },
  // v6: sorted inputs
  { 6,  6,  0, 1748649605 },
  // v7: RandomX PoW
  { 7,  7,  0, 1748649606 },
  // v8: bulletproofs, per-byte fee
  { 8,  8,  0, 1748649607 },
  // v9: bulletproofs non-optional
  { 9,  9,  0, 1748649608 },
  // v10: bulletproofs v2
  { 10, 10, 0, 1748649609 },
  // v11: CLSAG ring signatures
  { 11, 11, 0, 1748649610 },
  // v12: bulletproofs+ preparation
  { 12, 12, 0, 1748649611 },
  // v13: bulletproofs+
  { 13, 13, 0, 1748649612 },
  // v14: view tags
  { 14, 14, 0, 1748649613 },
  // v15: 2021 fee scaling
  { 15, 15, 0, 1748649614 },
  // v16: bulletproofs+ non-optional
  { 16, 16, 0, 1748649615 },
};
const size_t num_mainnet_hard_forks = sizeof(mainnet_hard_forks) / sizeof(mainnet_hard_forks[0]);
const uint64_t mainnet_hard_fork_version_1_till = 1;

const hardfork_t testnet_hard_forks[] = {
  // version 1 from the start of the blockchain
  { 1, 1, 0, 1341378000 },

  // version 2 starts from block 624634, which is on or around the 23rd of November, 2015. Fork time finalised on 2015-11-20. No fork voting occurs for the v2 fork.
  { 2, 624634, 0, 1445355000 },

  // versions 3-5 were passed in rapid succession from September 18th, 2016
  { 3, 800500, 0, 1472415034 },
  { 4, 801219, 0, 1472415035 },
  { 5, 802660, 0, 1472415036 + 86400*180 }, // add 5 months on testnet to shut the update warning up since there's a large gap to v6

  { 6, 971400, 0, 1501709789 },
  { 7, 1057027, 0, 1512211236 },
  { 8, 1057058, 0, 1533211200 },
  { 9, 1057778, 0, 1533297600 },
  { 10, 1154318, 0, 1550153694 },
  { 11, 1155038, 0, 1550225678 },
  { 12, 1308737, 0, 1569582000 },
  { 13, 1543939, 0, 1599069376 },
  { 14, 1544659, 0, 1599069377 },
  { 15, 1982800, 0, 1652727000 },
  { 16, 1983520, 0, 1652813400 },
};
const size_t num_testnet_hard_forks = sizeof(testnet_hard_forks) / sizeof(testnet_hard_forks[0]);
const uint64_t testnet_hard_fork_version_1_till = 624633;

const hardfork_t stagenet_hard_forks[] = {
  // version 1 from the start of the blockchain
  { 1, 1, 0, 1341378000 },

  // versions 2-7 in rapid succession from March 13th, 2018
  { 2, 32000, 0, 1521000000 },
  { 3, 33000, 0, 1521120000 },
  { 4, 34000, 0, 1521240000 },
  { 5, 35000, 0, 1521360000 },
  { 6, 36000, 0, 1521480000 },
  { 7, 37000, 0, 1521600000 },
  { 8, 176456, 0, 1537821770 },
  { 9, 177176, 0, 1537821771 },
  { 10, 269000, 0, 1550153694 },
  { 11, 269720, 0, 1550225678 },
  { 12, 454721, 0, 1571419280 },
  { 13, 675405, 0, 1598180817 },
  { 14, 676125, 0, 1598180818 },
  { 15, 1151000, 0, 1656629117 },
  { 16, 1151720, 0, 1656629118 },
};
const size_t num_stagenet_hard_forks = sizeof(stagenet_hard_forks) / sizeof(stagenet_hard_forks[0]);
