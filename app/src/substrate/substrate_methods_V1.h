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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_TIMESTAMP_V1 2
#define PD_CALL_GRANDPA_V1 3
#define PD_CALL_BALANCES_V1 4
#define PD_CALL_SUDO_V1 6
#define PD_CALL_STAKING_V1 9
#define PD_CALL_SESSION_V1 10
#define PD_CALL_TECHNICALMEMBERSHIP_V1 16

#define PD_CALL_BALANCES_TRANSFER_ALL_V1 4
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V1_t;

#define PD_CALL_SUDO_SUDO_V1 0
 typedef struct {
     pd_Call_t call;
 } pd_sudo_sudo_V1_t;

 #define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V1 1
 typedef struct {
     pd_Call_t call;
     pd_Weight_V1_t weight;
 } pd_sudo_sudo_unchecked_weight_V1_t;

 #define PD_CALL_SUDO_SET_KEY_V1 2 
 typedef struct {
     pd_LookupasStaticLookupSource_V1_t new_;
 } pd_sudo_set_key_V1_t;

#define PD_CALL_STAKING_BOND_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V1_t payee;
} pd_staking_bond_V1_t;

#define PD_CALL_STAKING_BOND_EXTRA_V1 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V1_t;

#define PD_CALL_STAKING_UNBOND_V1 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V1_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V1 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V1_t;

#define PD_CALL_STAKING_VALIDATE_V1 4
typedef struct {
    pd_ValidatorPrefs_V1_t prefs;
} pd_staking_validate_V1_t;

#define PD_CALL_STAKING_NOMINATE_V1 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V1_t targets;
} pd_staking_nominate_V1_t;

#define PD_CALL_STAKING_CHILL_V1 6
typedef struct {
} pd_staking_chill_V1_t;

#define PD_CALL_STAKING_SET_PAYEE_V1 7
typedef struct {
    pd_RewardDestination_V1_t payee;
} pd_staking_set_payee_V1_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V1 8
typedef struct {
    pd_LookupasStaticLookupSource_V1_t controller;
} pd_staking_set_controller_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V1 18
typedef struct {
    pd_AccountId_V1_t validator_stash;
    pd_EraIndex_V1_t era;
} pd_staking_payout_stakers_V1_t;

#define PD_CALL_STAKING_REBOND_V1 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V1 5
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V1_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V1 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V1_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V1 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V1_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V1 12
typedef struct {
} pd_staking_force_no_eras_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V1 13
typedef struct {
} pd_staking_force_new_era_V1_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V1 14
typedef struct {
    pd_VecAccountId_V1_t invulnerables;
} pd_staking_set_invulnerables_V1_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V1 15
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V1 16
typedef struct {
} pd_staking_force_new_era_always_V1_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V1 17
typedef struct {
    pd_EraIndex_V1_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V1_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V1 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V1_t;

#define PD_CALL_STAKING_REAP_STASH_V1 21
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V1_t;

#define PD_CALL_STAKING_KICK_V1 22
typedef struct {
    pd_VecLookupasStaticLookupSource_V1_t who;
} pd_staking_kick_V1_t;

#define PD_CALL_STAKING_CHILL_OTHER_V1 24
typedef struct {
    pd_AccountId_V1_t controller;
} pd_staking_chill_other_V1_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V1 25
typedef struct {
    pd_AccountId_V1_t validator_stash;
} pd_staking_force_apply_min_commission_V1_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V1 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V1 0
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_add_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V1 1
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_remove_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V1 2
typedef struct {
    pd_AccountId_V1_t remove;
    pd_AccountId_V1_t add;
} pd_technicalmembership_swap_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V1 3
typedef struct {
    pd_VecAccountId_V1_t members;
} pd_technicalmembership_reset_members_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V1 4
typedef struct {
    pd_AccountId_V1_t new_;
} pd_technicalmembership_change_key_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V1 5
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_set_prime_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V1 6
typedef struct {
} pd_technicalmembership_clear_prime_V1_t;

#endif

typedef union {
    pd_balances_transfer_all_V1_t balances_transfer_all_V1;
    pd_staking_bond_V1_t staking_bond_V1;
    pd_staking_bond_extra_V1_t staking_bond_extra_V1;
    pd_staking_unbond_V1_t staking_unbond_V1;
    pd_staking_withdraw_unbonded_V1_t staking_withdraw_unbonded_V1;
    pd_staking_validate_V1_t staking_validate_V1;
    pd_staking_nominate_V1_t staking_nominate_V1;
    pd_staking_chill_V1_t staking_chill_V1;
    pd_staking_set_payee_V1_t staking_set_payee_V1;
    pd_staking_set_controller_V1_t staking_set_controller_V1;
    pd_staking_payout_stakers_V1_t staking_payout_stakers_V1;
    pd_staking_rebond_V1_t staking_rebond_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_balances_force_unreserve_V1_t balances_force_unreserve_V1;
    pd_sudo_set_key_V1_t sudo_set_key_V1;
    pd_sudo_sudo_V1_t sudo_sudo_V1;
    pd_sudo_sudo_unchecked_weight_V1_t sudo_sudo_unchecked_weight_V1;
    pd_staking_set_validator_count_V1_t staking_set_validator_count_V1;
    pd_staking_increase_validator_count_V1_t staking_increase_validator_count_V1;
    pd_staking_force_no_eras_V1_t staking_force_no_eras_V1;
    pd_staking_force_new_era_V1_t staking_force_new_era_V1;
    pd_staking_set_invulnerables_V1_t staking_set_invulnerables_V1;
    pd_staking_force_unstake_V1_t staking_force_unstake_V1;
    pd_staking_force_new_era_always_V1_t staking_force_new_era_always_V1;
    pd_staking_cancel_deferred_slash_V1_t staking_cancel_deferred_slash_V1;
    pd_staking_set_history_depth_V1_t staking_set_history_depth_V1;
    pd_staking_reap_stash_V1_t staking_reap_stash_V1;
    pd_staking_kick_V1_t staking_kick_V1;
    pd_staking_chill_other_V1_t staking_chill_other_V1;
    pd_staking_force_apply_min_commission_V1_t staking_force_apply_min_commission_V1;
    pd_grandpa_note_stalled_V1_t grandpa_note_stalled_V1;
    pd_technicalmembership_add_member_V1_t technicalmembership_add_member_V1;
    pd_technicalmembership_remove_member_V1_t technicalmembership_remove_member_V1;
    pd_technicalmembership_swap_member_V1_t technicalmembership_swap_member_V1;
    pd_technicalmembership_reset_members_V1_t technicalmembership_reset_members_V1;
    pd_technicalmembership_change_key_V1_t technicalmembership_change_key_V1;
    pd_technicalmembership_set_prime_V1_t technicalmembership_set_prime_V1;
    pd_technicalmembership_clear_prime_V1_t technicalmembership_clear_prime_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t source;
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V1 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop