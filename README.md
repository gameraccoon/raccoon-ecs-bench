2021-05-24T21:39:40+02:00
CPU Caches:
  L1 Data 24 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 1024 KiB (x2)
Load Average: 1.52, 0.96, 0.60
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create empty entity manager | 190 ns | 190 ns | 3680621
Add one entity without components | 230 ns | 230 ns | 2714207
Add one entity with one component | 382 ns | 381 ns | 2159029
Add one entity with one component while having one index (the component not in the index) | 382 ns | 381 ns | 2275645
Add one entity with one component while having one index (the component in the index) | 455 ns | 454 ns | 1831467
Add one entity with 16 components | 3619 ns | 3611 ns | 220943
Add one entity with 16 component while having 8 indexes (the components not in the indexes) | 4674 ns | 4666 ns | 149106
Add one entity with 16 component while having 1 small index (the components in the index) | 3916 ns | 3907 ns | 207826
Add one entity with 16 component while having 1 big index (the components in the index) | 6584 ns | 6573 ns | 107079
Add one entity with 16 component while having 8 different index (the components are in the indexes) | 11256 ns | 11240 ns | 61912
Iterate over matching pairs of components (around 1000) from 4000 entities | 7870 ns | 7864 ns | 89903
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 397859 ns | 396850 ns | 1737
Select matching pairs of components (around 1000) from 4000 entities | 5744 ns | 5740 ns | 122954
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 302183 ns | 301462 ns | 2213
Create and transfer entity without components to another entity manager | 383 ns | 382 ns | 1854437
Create and transfer entity with two components to another entity manager | 859 ns | 857 ns | 846265
Create and transfer entity with two components to another entity manager (both have one index with both components) | 1158 ns | 1156 ns | 620765
