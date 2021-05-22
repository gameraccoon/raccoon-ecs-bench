2021-05-22T23:37:40+02:00

Run on (4 X 2560 MHz CPU s)

CPU Caches:

  L1 Data 24 KiB (x4)
  
  L1 Instruction 32 KiB (x4)
  
  L2 Unified 1024 KiB (x2)
  
Load Average: 2.19, 2.58, 1.92

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

| Benchmark                                                         |       Time   |         CPU  |  Iterations
| ----------------------------------------------------------------- | ------------ | ------------ | ------------
| BM_EmptyEntityManagerCreation                                     |     190 ns   |       190 ns |     3679963
| BM_EmptyEntityAddition                                            |     232 ns   |       231 ns |     2680681
| BM_CreateEntityWithOneComponent                                   |     358 ns   |       357 ns |     2094653
| BM_CreateEntityWithOneComponentWithOneNonMatchingIndex            |     400 ns   |       399 ns |     2171809
| BM_CreateEntityWithOneComponentInOneIndex                         |     465 ns   |       464 ns |     1744867
| BM_CreateEntityWithSixteenComponents                              |    3776 ns   |      3768 ns |      210972
| BM_CreateEntityWithSixteenComponentsWithEightNonMatchingIndexes   |    4681 ns   |      4672 ns |      144155
| BM_CreateEntityWithSixteenComponentsInOneSmallIndex               |    4012 ns   |      4002 ns |      202161
| BM_CreateEntityWithSixteenComponentsInOneBigIndex                 |    6755 ns   |      6738 ns |      106183
| BM_CreateEntityWithSixteenComponentsInEightDifferentIndexes       |   11371 ns   |     11352 ns |       60041
| BM_IterateOverAbout1000PairsOfComponentsFrom4000Entities          |    7968 ns   |      7909 ns |       88207
| BM_SelectAbout1000PairsOfComponentsFrom4000Entities               |    5804 ns   |      5794 ns |      121213
| BM_CreateAndTransferEmptyEntity                                   |     398 ns   |       397 ns |     1846206
| BM_CreateAndTransferEntityWithTwoComponents                       |     844 ns   |       841 ns |      843724
| BM_CreateAndTransferEntityWithTwoComponentsInOneIndex             |    1131 ns   |      1129 ns |      631373
