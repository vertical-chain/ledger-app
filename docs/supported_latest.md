# Vertical  1.4212.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> |
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `u64` now <br/> |

## Grandpa

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Note stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`BalanceOfT` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`BalanceOfT` new_free <br/>`BalanceOfT` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`BalanceOfT` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`BalanceOfT` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> |

## Sudo

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
| Set key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> | 
| Sudo |    | :heavy_check_mark: |   | `Call` call <br/> | 
| Sudo as |    |  |   | `AccountId` who <br/>, `Call` call <br/> | 
| Sudo unchecked weight |    | :heavy_check_mark: |   | `Call` call <br/> | `Weight` weight <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## Staking

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/>`BalanceOfT` value <br/>`RewardDestination` payee <br/> |
|Bond extra | :heavy_check_mark:  | :heavy_check_mark: |   | `BalanceOfT` max_additional <br/> |
|Unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `BalanceOfT` value <br/> |
|Withdraw Unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> |
|Validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> |
|Nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` targets <br/> |
|Chill | :heavy_check_mark:  | :heavy_check_mark: |   |  |
|Set payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> |
|Set controller | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/> |
|Set validator count |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Increase validator count |    | :heavy_check_mark: |   | `u32` additional <br/> |
|Scale validator count |    |   |   | `Percent` factor <br/> |
|Force no eras |    | :heavy_check_mark: |   |  |
|Force new era |    | :heavy_check_mark: |   |  |
|Set invulnerables |    | heavy_check_mark |   | `VecAccountId` invulnerables <br/> |
|Force unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Force new era always |    | :heavy_check_mark: |   |  |
|Cancel deferred slash |    | heavy_check_mark |   | `EraIndex` era <br/>`Vecu32` slash_indices <br/> |
|Payout stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> |
|Rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `BalanceOfT` value <br/> |
|Set history depth |    | :heavy_check_mark: |   | `EraIndex` new_history_depth <br/>`u32` era_items_deleted <br/> |
|Reap stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Kick |    | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` who <br/> |
|Set staking limits |    |   |   | `BalanceOfT` min_nominator_bond <br/>`BalanceOfT` min_validator_bond <br/>`Optionu32` max_nominator_count <br/>`Optionu32` max_validator_count <br/>`OptionPercent` threshold  <br/> |
|Chill other |    | :heavy_check_mark: |   | `AccountId` controller <br/> |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## Babe

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Plan config change |    |   |   | `NextConfigDescriptor` config <br/> |

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Submit unsigned |    |   |   | `BoxRawSolutionSolutionOfT` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> |
|Set minimum untrusted score |    |   |   | `OptionElectionScore` maybe_next_score <br/> |
|Set emergency election result |    |   |   | `SupportsAccountId` supports <br/> |
|Submit |    |   |   | `BoxRawSolutionSolutionOfT` raw_solution <br/> |

## Membership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` new <br/> |
|Set prime |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: | :heavy_check_mark: |  |