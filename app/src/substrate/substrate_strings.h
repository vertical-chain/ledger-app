/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Modules names
static const char* STR_MO_SYSTEM = "System";
static const char* STR_MO_TIMESTAMP = "Timestamp";
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_SUDO = "Sudo";
static const char* STR_MO_STAKING = "Staking";
static const char* STR_MO_SESSION = "Session";
static const char* STR_MO_GRANDPA = "Grandpa";
static const char* STR_MO_TECHNICALMEMBERSHIP = "Membership";

// Methods names
static const char* STR_ME_FILL_BLOCK = "Fill block";
static const char* STR_ME_REMARK = "Remark";
static const char* STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char* STR_ME_SET_CODE = "Set code";
static const char* STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char* STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char* STR_ME_SET = "Set";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_SET_BALANCE = "Set balance";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char* STR_ME_BOND = "Bond";
static const char* STR_ME_BOND_EXTRA = "Bond extra";
static const char* STR_ME_UNBOND = "Unbond";
static const char* STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char* STR_ME_VALIDATE = "Validate";
static const char* STR_ME_NOMINATE = "Nominate";
static const char* STR_ME_CHILL = "Chill";
static const char* STR_ME_SET_PAYEE = "Set payee";
static const char* STR_ME_SET_CONTROLLER = "Set controller";
static const char* STR_ME_SET_VALIDATOR_COUNT = "Set validator count";
static const char* STR_ME_INCREASE_VALIDATOR_COUNT = "Increase validator count";
static const char* STR_ME_FORCE_NO_ERAS = "Force no eras";
static const char* STR_ME_FORCE_NEW_ERA = "Force new era";
static const char* STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char* STR_ME_FORCE_UNSTAKE = "Force unstake";
static const char* STR_ME_FORCE_NEW_ERA_ALWAYS = "Force new era always";
static const char* STR_ME_CANCEL_DEFERRED_SLASH = "Cancel deferred slash";
static const char* STR_ME_PAYOUT_STAKERS = "Payout stakers";
static const char* STR_ME_REBOND = "Rebond";
static const char* STR_ME_SET_HISTORY_DEPTH = "Set history depth";
static const char* STR_ME_REAP_STASH = "Reap stash";
static const char* STR_ME_KICK = "Kick";
static const char* STR_ME_CHILL_OTHER = "Chill other";
static const char* STR_ME_SUDO = "Sudo";
static const char* STR_ME_SUDO_SET_KEY = "Set key";
static const char* STR_ME_SUDO_UNCHECKED_WEIGHT = "Sudo unchecked weight";
static const char* STR_ME_SET_KEYS = "Set keys";
static const char* STR_ME_PURGE_KEYS = "Purge keys";
static const char* STR_ME_NOTE_STALLED = "Note stalled";
static const char* STR_ME_REMOVE_MEMBER = "Remove member";
static const char* STR_ME_ADD_MEMBER = "Add member";
static const char* STR_ME_SWAP_MEMBER = "Swap member";
static const char* STR_ME_RESET_MEMBERS = "Reset members";
static const char* STR_ME_CHANGE_KEY = "Change key";
static const char* STR_ME_SET_PRIME = "Set prime";
static const char* STR_ME_CLEAR_PRIME = "Clear prime";

// Items names
static const char* STR_IT_ratio = "Ratio";
static const char* STR_IT_remark = "Remark";
static const char* STR_IT_pages = "Pages";
static const char* STR_IT_code = "Code";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_now = "Now";
static const char* STR_IT_index = "Index";
static const char* STR_IT_new = "New";
static const char* STR_IT_freeze = "Freeze";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_new_reserved = "New reserved";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_controller = "Controller";
static const char* STR_IT_payee = "Payee";
static const char* STR_IT_num_slashing_spans = "Num slashing spans";
static const char* STR_IT_prefs = "Prefs";
static const char* STR_IT_targets = "Targets";
static const char* STR_IT_additional = "Additional";
static const char* STR_IT_invulnerables = "Invulnerables";
static const char* STR_IT_stash = "Stash";
static const char* STR_IT_era = "Era";
static const char* STR_IT_slash_indices = "Slash indices";
static const char* STR_IT_validator_stash = "Validator stash";
static const char* STR_IT_new_history_depth = "New history depth";
static const char* STR_IT_era_items_deleted = "Era items deleted";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_delay = "Delay";
static const char* STR_IT_best_finalized_block_number = "Best finalized block number";
static const char* STR_IT_approve = "Approve";
static const char* STR_IT_remove = "Remove";
static const char* STR_IT_add = "Add";
static const char* STR_IT_members = "Members";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_call = "Call";
static const char* STR_IT_weight_limit = "Weight";

#ifdef __cplusplus
}
#endif