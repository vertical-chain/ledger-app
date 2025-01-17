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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V1_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaPublic_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Public_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Signature_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Public_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Signature_V1_t;

typedef struct {
    uint8_t value;
} pd_Vote_V1_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V1_t;

typedef struct {
    pd_Vote_V1_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V1_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V1_t id;
        pd_CompactAccountIndex_V1_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Signature_V1_t ed25519;
        pd_Sr25519Signature_V1_t sr25519;
        pd_EcdsaSignature_V1_t ecdsa;
    };
} pd_MultiSignature_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Public_V1_t ed25519;
        pd_Sr25519Public_V1_t sr25519;
        pd_EcdsaPublic_V1_t ecdsa;
    };
} pd_MultiSigner_V1_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V1_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_StatementKind_V1_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleBalanceOfTBalanceOfTBlockNumber_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePeriodBlockNumber_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V1_t voteStandard;
        pd_AccountVoteSplit_V1_t voteSplit;
    };
} pd_AccountVote_V1_t;

typedef struct {
    uint8_t value;
    pd_Balance_t freeBalance;
} pd_BondExtraBalanceOfT_V1_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V1_t set;
} pd_ConfigOpAccountId_V1_t;

typedef struct {
    uint8_t value;
    pd_Balance_t set;
} pd_ConfigOpBalanceOfT_V1_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V1_t;

typedef struct {
    uint8_t some;
    pd_MultiSignature_V1_t contained;
} pd_OptionMultiSignature_V1_t;

typedef struct {
    uint8_t some;
    pd_MultiSigner_V1_t contained;
} pd_OptionMultiSigner_V1_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V1_t contained;
} pd_OptionTimepoint_V1_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V1_t accountId;
} pd_RewardDestination_V1_t;

typedef struct {
    pd_CompactPerBill_V1_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupasStaticLookupSource_V1_t;

typedef struct {
    pd_BalanceOf_t locked;
    pd_BalanceOf_t per_block;
    pd_BlockNumber_t starting_block;
} pd_VestingInfo_V1_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AuthorityIdasRuntimeAppPublicSignature_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxCallOrHashOfT_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHashBlockNumber_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHeader_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxIdentityInfoMaxAdditionalFields_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxPalletsOrigin_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxRawSolutionSolutionOfMinerConfig_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiAssets_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiLocation_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ConfigOpPerbill_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ConfigOpPercent_V1_t;

typedef struct {
    uint8_t value;
    uint32_t set;
} pd_ConfigOpu32_V1_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V1_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeadData_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeartbeatBlockNumber_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HrmpChannelId_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_JudgementBalanceOfT_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Judgement_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LeasePeriodOfT_V1_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_NextConfigDescriptor_V1_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V1_t contained;
} pd_OptionAccountId_V1_t;

typedef struct {
    uint8_t some;
    pd_ElectionScore_V1_t contained;
} pd_OptionElectionScore_V1_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V1_t contained;
} pd_OptionProxyType_V1_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V1_t contained;
} pd_OptionReferendumIndex_V1_t;

typedef struct {
    uint8_t some;
    pd_StatementKind_V1_t contained;
} pd_OptionStatementKind_V1_t;

typedef struct {
    uint8_t some;
    pd_TupleBalanceOfTBalanceOfTBlockNumber_V1_t contained;
} pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V1_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V1_t contained;
} pd_OptionXcmVersion_V1_t;

typedef struct {
    uint8_t some;
    pd_schedulePeriodBlockNumber_V1_t contained;
} pd_OptionschedulePeriodBlockNumber_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V1_t;

typedef struct {
    uint32_t value;
} pd_ParaId_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainsInherentDataHeader_V1_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V1_t;

typedef struct {
    uint8_t value;
} pd_Percent_V1_t;

typedef struct {
    uint32_t value;
} pd_PoolId_V1_t;

typedef struct {
    uint8_t value;
} pd_PoolState_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_PvfCheckStatement_V1_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Renouncing_V1_t;

typedef struct {
    uint32_t value;
} pd_SessionIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SolutionOrSnapshotSize_V1_t;

typedef struct {
pd_AccountId_V1_t account_id;
    pd_Bytes_t extended_balance;
 } pd_SpNposElectionsSupportVoter_V1_t;

 typedef struct {
     uint64_t _len;
     const uint8_t* _ptr;
     uint64_t _lenBuffer;
 } pd_VecSpNposElectionsSupportVoters_V1_t;

 typedef struct {
    pd_Bytes_t total;
    pd_VecSpNposElectionsSupportVoters_V1_t voters;
 } pd_SpNposElectionsSupport_V1_t;

 typedef struct {
    pd_AccountId_V1_t account_id;
    pd_SpNposElectionsSupport_V1_t supports;
} pd_SupportsAccountId_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidationCodeHash_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidationCode_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidatorSignature_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSupports_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V1_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V1_t;

typedef struct {
    uint64_t value;
} pd_Weight_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePriority_V1_t;

#ifdef __cplusplus
}
#endif