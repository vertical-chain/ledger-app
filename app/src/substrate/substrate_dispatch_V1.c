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

#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V1(
    parser_context_t* c, pd_balances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V1(
    parser_context_t* c, pd_balances_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V1(
    parser_context_t* c, pd_balances_transfer_keep_alive_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V1(
    parser_context_t* c, pd_balances_transfer_all_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V1(
    parser_context_t* c, pd_staking_bond_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V1(
    parser_context_t* c, pd_staking_bond_extra_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V1(
    parser_context_t* c, pd_staking_unbond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V1(
    parser_context_t* c, pd_staking_withdraw_unbonded_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V1(
    parser_context_t* c, pd_staking_validate_V1_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V1(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V1(
    parser_context_t* c, pd_staking_nominate_V1_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V1(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V1(
    parser_context_t* c, pd_staking_chill_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V1(
    parser_context_t* c, pd_staking_set_payee_V1_t* m)
{
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V1(
    parser_context_t* c, pd_staking_set_controller_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V1(
    parser_context_t* c, pd_staking_payout_stakers_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V1(
    parser_context_t* c, pd_staking_rebond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V1(
    parser_context_t* c, pd_session_set_keys_V1_t* m)
{
    CHECK_ERROR(_readKeys_V1(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V1(
    parser_context_t* c, pd_session_purge_keys_V1_t* m)
{
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V1(
    parser_context_t* c, pd_system_fill_block_V1_t* m)
{
    CHECK_ERROR(_readPerbill_V1(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V1(
    parser_context_t* c, pd_system_remark_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V1(
    parser_context_t* c, pd_system_set_heap_pages_V1_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V1(
    parser_context_t* c, pd_system_set_code_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V1(
    parser_context_t* c, pd_system_set_code_without_checks_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V1(
    parser_context_t* c, pd_system_remark_with_event_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V1(
    parser_context_t* c, pd_timestamp_set_V1_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V1(
    parser_context_t* c, pd_balances_set_balance_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V1(
    parser_context_t* c, pd_balances_force_unreserve_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V1(
     parser_context_t* c, pd_sudo_sudo_V1_t* m)
 {
     CHECK_ERROR(_readCall(c, &m->call))
     return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V1(
     parser_context_t* c, pd_sudo_sudo_unchecked_weight_V1_t* m)
 {
     CHECK_ERROR(_readCall(c, &m->call))
     CHECK_ERROR(_readWeight_V1(c, &m->weight))
     return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V1(
     parser_context_t* c, pd_sudo_set_key_V1_t* m)
 {
     CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->new_))
     return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V1(
    parser_context_t* c, pd_staking_set_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V1(
    parser_context_t* c, pd_staking_increase_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V1(
    parser_context_t* c, pd_staking_force_no_eras_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V1(
    parser_context_t* c, pd_staking_force_new_era_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V1(
    parser_context_t* c, pd_staking_set_invulnerables_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V1(
    parser_context_t* c, pd_staking_force_unstake_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V1(
    parser_context_t* c, pd_staking_force_new_era_always_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V1(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V1_t* m)
{
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V1(
    parser_context_t* c, pd_staking_set_history_depth_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V1(
    parser_context_t* c, pd_staking_reap_stash_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V1(
    parser_context_t* c, pd_staking_kick_V1_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V1(
    parser_context_t* c, pd_staking_chill_other_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V1(
    parser_context_t* c, pd_grandpa_note_stalled_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V1(
    parser_context_t* c, pd_technicalmembership_add_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V1(
    parser_context_t* c, pd_technicalmembership_remove_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V1(
    parser_context_t* c, pd_technicalmembership_swap_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->remove))
    CHECK_ERROR(_readAccountId_V1(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V1(
    parser_context_t* c, pd_technicalmembership_reset_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V1(
    parser_context_t* c, pd_technicalmembership_change_key_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V1(
    parser_context_t* c, pd_technicalmembership_set_prime_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V1(
    parser_context_t* c, pd_technicalmembership_clear_prime_V1_t* m)
{
    return parser_ok;
}

#endif

parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->nested.balances_transfer_V1))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->nested.balances_force_transfer_V1))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->nested.balances_transfer_keep_alive_V1))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V1(c, &method->basic.balances_transfer_all_V1))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->basic.staking_bond_V1))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->basic.staking_bond_extra_V1))
        break;
    case 2306: /* module 9 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->basic.staking_unbond_V1))
        break;
    case 2307: /* module 9 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
        break;
    case 2308: /* module 9 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->basic.staking_validate_V1))
        break;
    case 2309: /* module 9 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->basic.staking_nominate_V1))
        break;
    case 2310: /* module 9 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->basic.staking_chill_V1))
        break;
    case 2311: /* module 9 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->basic.staking_set_payee_V1))
        break;
    case 2312: /* module 9 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->basic.staking_set_controller_V1))
        break;
    case 2322: /* module 9 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->basic.staking_payout_stakers_V1))
        break;
    case 2323: /* module 9 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->basic.staking_rebond_V1))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V1(c, &method->basic.session_set_keys_V1))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V1(c, &method->basic.session_purge_keys_V1))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V1(c, &method->nested.system_fill_block_V1))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V1(c, &method->nested.system_remark_V1))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V1(c, &method->nested.system_set_heap_pages_V1))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V1(c, &method->nested.system_set_code_V1))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V1(c, &method->nested.system_set_code_without_checks_V1))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V1(c, &method->nested.system_remark_with_event_V1))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V1(c, &method->basic.timestamp_set_V1))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V1(c, &method->nested.balances_set_balance_V1))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V1(c, &method->basic.balances_force_unreserve_V1))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V1(c, &method->basic.sudo_sudo_V1))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V1(c, &method->basic.sudo_sudo_unchecked_weight_V1))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V1(c, &method->basic.sudo_set_key_V1))
        break;
    case 2313: /* module 9 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
        break;
    case 2314: /* module 9 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
        break;
    case 2316: /* module 9 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V1(c, &method->basic.staking_force_no_eras_V1))
        break;
    case 2317: /* module 9 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V1(c, &method->basic.staking_force_new_era_V1))
        break;
    case 2318: /* module 9 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V1(c, &method->basic.staking_set_invulnerables_V1))
        break;
    case 2319: /* module 9 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V1(c, &method->basic.staking_force_unstake_V1))
        break;
    case 2320: /* module 9 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V1(c, &method->basic.staking_force_new_era_always_V1))
        break;
    case 2321: /* module 9 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V1(c, &method->basic.staking_cancel_deferred_slash_V1))
        break;
    case 2324: /* module 9 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V1(c, &method->basic.staking_set_history_depth_V1))
        break;
    case 2325: /* module 9 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
        break;
    case 2326: /* module 9 call 22 */
        CHECK_ERROR(_readMethod_staking_kick_V1(c, &method->basic.staking_kick_V1))
        break;
    case 2328: /* module 9 call 24 */
        CHECK_ERROR(_readMethod_staking_chill_other_V1(c, &method->basic.staking_chill_other_V1))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V1(c, &method->basic.grandpa_note_stalled_V1))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V1(c, &method->basic.technicalmembership_add_member_V1))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V1(c, &method->basic.technicalmembership_remove_member_V1))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V1(c, &method->basic.technicalmembership_swap_member_V1))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V1(c, &method->basic.technicalmembership_reset_members_V1))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V1(c, &method->basic.technicalmembership_change_key_V1))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V1(c, &method->basic.technicalmembership_set_prime_V1))
        break;
    case 4102: /* module 16 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V1(c, &method->basic.technicalmembership_clear_prime_V1))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V1(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 4:
        return STR_MO_BALANCES;
    case 9:
        return STR_MO_STAKING;
    case 10:
        return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 2:
        return STR_MO_TIMESTAMP;
    case 3:
        return STR_MO_GRANDPA;
    case 6:
        return STR_MO_SUDO;
    case 16:
        return STR_MO_TECHNICALMEMBERSHIP;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return STR_ME_TRANSFER;
    case 1026: /* module 4 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1027: /* module 4 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1028: /* module 4 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 2304: /* module 9 call 0 */
        return STR_ME_BOND;
    case 2305: /* module 9 call 1 */
        return STR_ME_BOND_EXTRA;
    case 2306: /* module 9 call 2 */
        return STR_ME_UNBOND;
    case 2307: /* module 9 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 2308: /* module 9 call 4 */
        return STR_ME_VALIDATE;
    case 2309: /* module 9 call 5 */
        return STR_ME_NOMINATE;
    case 2310: /* module 9 call 6 */
        return STR_ME_CHILL;
    case 2311: /* module 9 call 7 */
        return STR_ME_SET_PAYEE;
    case 2312: /* module 9 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 2322: /* module 9 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 2323: /* module 9 call 19 */
        return STR_ME_REBOND;
    case 2560: /* module 10 call 0 */
        return STR_ME_SET_KEYS;
    case 2561: /* module 10 call 1 */
        return STR_ME_PURGE_KEYS;
    default:
        return _getMethod_Name_V1_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V1_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 512: /* module 2 call 0 */
        return STR_ME_SET;
    case 770: /* module 3 call 2 */
        return STR_ME_NOTE_STALLED;
    case 1025: /* module 4 call 1 */
        return STR_ME_SET_BALANCE;
    case 1029: /* module 4 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1536: /* module 6 call 0 */
        return STR_ME_SUDO;
    case 1537: /* module 6 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 1538: /* module 6 call 2 */
        return STR_ME_SUDO_SET_KEY;
    case 2313: /* module 9 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 2314: /* module 9 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 2316: /* module 9 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 2317: /* module 9 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 2318: /* module 9 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 2319: /* module 9 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 2320: /* module 9 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 2321: /* module 9 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 2324: /* module 9 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 2325: /* module 9 call 21 */
        return STR_ME_REAP_STASH;
    case 2326: /* module 9 call 22 */
        return STR_ME_KICK;
    case 2328: /* module 9 call 24 */
        return STR_ME_CHILL_OTHER;
    case 4096: /* module 16 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4097: /* module 16 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4098: /* module 16 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4099: /* module 16 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4100: /* module 16 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4101: /* module 16 call 5 */
        return STR_ME_SET_PRIME;
    case 4102: /* module 16 call 6 */
        return STR_ME_CLEAR_PRIME;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 3;
    case 1027: /* module 4 call 3 */
        return 2;
    case 1028: /* module 4 call 4 */
        return 2;
    case 2304: /* module 9 call 0 */
        return 3;
    case 2305: /* module 9 call 1 */
        return 1;
    case 2306: /* module 9 call 2 */
        return 1;
    case 2307: /* module 9 call 3 */
        return 1;
    case 2308: /* module 9 call 4 */
        return 1;
    case 2309: /* module 9 call 5 */
        return 1;
    case 2310: /* module 9 call 6 */
        return 0;
    case 2311: /* module 9 call 7 */
        return 1;
    case 2312: /* module 9 call 8 */
        return 1;
    case 2322: /* module 9 call 18 */
        return 2;
    case 2323: /* module 9 call 19 */
        return 1;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 0;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 512: /* module 2 call 0 */
        return 1;
    case 770: /* module 3 call 2 */
        return 2;
    case 1025: /* module 4 call 1 */
        return 3;
    case 1029: /* module 4 call 5 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 1;
    case 1537: /* module 6 call 1 */
        return 2;
    case 1538: /* module 6 call 2 */
        return 1;
    case 2313: /* module 9 call 9 */
        return 1;
    case 2314: /* module 9 call 10 */
        return 1;
    case 2316: /* module 9 call 12 */
        return 0;
    case 2317: /* module 9 call 13 */
        return 0;
    case 2318: /* module 9 call 14 */
        return 1;
    case 2319: /* module 9 call 15 */
        return 2;
    case 2320: /* module 9 call 16 */
        return 0;
    case 2321: /* module 9 call 17 */
        return 2;
    case 2324: /* module 9 call 20 */
        return 2;
    case 2325: /* module 9 call 21 */
        return 2;
    case 2326: /* module 9 call 22 */
        return 1;
    case 2328: /* module 9 call 24 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 1;
    case 4097: /* module 16 call 1 */
        return 1;
    case 4098: /* module 16 call 2 */
        return 2;
    case 4099: /* module 16 call 3 */
        return 1;
    case 4100: /* module 16 call 4 */
        return 1;
    case 4101: /* module 16 call 5 */
        return 1;
    case 4102: /* module 16 call 6 */
        return 0;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2310: /* module 9 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2311: /* module 9 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2312: /* module 9 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2322: /* module 9 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2323: /* module 9 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new;
        default:
            return NULL;
        }
    case 2313: /* module 9 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new;
        default:
            return NULL;
        }
    case 2314: /* module 9 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 2316: /* module 9 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2317: /* module 9 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2318: /* module 9 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 2319: /* module 9 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2320: /* module 9 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2321: /* module 9 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 2324: /* module 9 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT_era_items_deleted;
        default:
            return NULL;
        }
    case 2325: /* module 9 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2326: /* module 9 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2328: /* module 9 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new;
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(
    pd_Method_V1_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V1 - source */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_force_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_force_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_transfer_keep_alive_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.balances_transfer_all_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V1 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V1.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_bond_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_bond_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_extra_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_unbond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V1 - prefs */;
            return _toStringValidatorPrefs_V1(
                &m->basic.staking_validate_V1.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V1 - targets */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_nominate_V1.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2310: /* module 9 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2311: /* module 9 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_set_payee_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2312: /* module 9 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_set_controller_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2322: /* module 9 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V1 - validator_stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_payout_stakers_V1.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_payout_stakers_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2323: /* module 9 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_rebond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V1 - keys */;
            return _toStringKeys_V1(
                &m->basic.session_set_keys_V1.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V1 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V1.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V1 - ratio */;
            return _toStringPerbill_V1(
                &m->nested.system_fill_block_V1.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V1 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V1.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V1 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V1 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V1 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V1.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V1 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_set_balance_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V1 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V1.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V1 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V1.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.balances_force_unreserve_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V1 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V1- call */;
            return _toStringCall(
                &m->basic.sudo_sudo_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V1- call */
            return _toStringCall(
                &m->basic.sudo_sudo_unchecked_weight_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V1- weight */
            return _toStringWeight_V1(
                &m->basic.sudo_sudo_unchecked_weight_V1.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V1- new */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.sudo_set_key_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2313: /* module 9 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V1 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2314: /* module 9 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V1 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V1.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2316: /* module 9 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2317: /* module 9 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2318: /* module 9 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V1 - invulnerables */;
            return _toStringVecAccountId_V1(
                &m->basic.staking_set_invulnerables_V1.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2319: /* module 9 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_force_unstake_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2320: /* module 9 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2321: /* module 9 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_cancel_deferred_slash_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V1 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V1.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2324: /* module 9 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V1 - new_history_depth */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V1.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V1 - era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V1.era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2325: /* module 9 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_reap_stash_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2326: /* module 9 call 22 */
        switch (itemIdx) {
        case 0: /* staking_kick_V1 - who */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_kick_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2328: /* module 9 call 24 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V1 - controller */;
            return _toStringAccountId_V1(
                &m->basic.staking_chill_other_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_add_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_remove_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V1 - remove */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_swap_member_V1.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V1 - add */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_swap_member_V1.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V1 - members */;
            return _toStringVecAccountId_V1(
                &m->basic.technicalmembership_reset_members_V1.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_change_key_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_set_prime_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2307: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2319: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2325: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: // Timestamp:Set
    case 770: // Grandpa:Note stalled
    case 1028: // Balances:Transfer all
    case 1029: // Balances:Force unreserve
    case 1536: // Sudo:Sudo
    case 1537: // Sudo:Sudo unchecked weight
    case 1538: // Sudo:Set key
    case 2304: // Staking:Bond
    case 2305: // Staking:Bond extra
    case 2306: // Staking:Unbond
    case 2307: // Staking:Withdraw Unbonded
    case 2308: // Staking:Validate
    case 2309: // Staking:Nominate
    case 2310: // Staking:Chill
    case 2311: // Staking:Set payee
    case 2312: // Staking:Set controller
    case 2313: // Staking:Set validator count
    case 2314: // Staking:Increase validator count
    case 2316: // Staking:Force no eras
    case 2317: // Staking:Force new era
    case 2318: // Staking:Set invulnerables
    case 2319: // Staking:Force unstake
    case 2320: // Staking:Force new era always
    case 2321: // Staking:Cancel deferred slash
    case 2322: // Staking:Payout stakers
    case 2323: // Staking:Rebond
    case 2324: // Staking:Set history depth
    case 2325: // Staking:Reap stash
    case 2326: // Staking:Kick
    case 2328: // Staking:Chill other
    case 2560: // Session:Set keys
    case 2561: // Session:Purge keys
    case 4357: // PhragmenElection:Clean defunct voters
        return false;
    default:
        return true;
    }
}