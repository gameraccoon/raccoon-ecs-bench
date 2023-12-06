2023-12-06T21:06:30+01:00  
Run on (8 X 2424 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 64.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 128.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 4096.0 KiB (x2)  
Load Average: 0.224609, 0.356445, 0.568848

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 24 ns | 24 ns | 28663743
Add one entity without components | 21 ns | 21 ns | 33809001
Add one entity with one component | 30 ns | 30 ns | 24293992
Add one entity with one component while having one index (the component is not in the index) | 30 ns | 30 ns | 24100710
Add one entity with one component while having one index (the component is in the index) | 43 ns | 43 ns | 17540922
Add one entity with 16 components | 286 ns | 286 ns | 2521696
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 453 ns | 453 ns | 1552703
Add one entity with 16 components while having 1 small index (the components are in the index) | 299 ns | 298 ns | 2514249
Add one entity with 16 components while having 1 big index (the components are in the index) | 544 ns | 544 ns | 1284922
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 1014 ns | 1014 ns | 692284
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 99 ns | 99 ns | 6975838
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 202 ns | 202 ns | 3388268
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 398 ns | 398 ns | 1780757
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 790 ns | 790 ns | 896648
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 2891 ns | 2891 ns | 235761
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 5292 ns | 5291 ns | 127998
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 10230 ns | 10229 ns | 67983
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 20568 ns | 20566 ns | 33683
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 41158 ns | 41155 ns | 16866
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 10867 ns | 10866 ns | 63834
Select matching pairs of components around 1/4 from total 1024 entities | 464 ns | 464 ns | 1500393
Select matching pairs of components around 1/4 from total 2048 entities | 1030 ns | 1030 ns | 658354
Select matching pairs of components around 1/4 from total 4096 entities | 2031 ns | 2031 ns | 345523
Select matching pairs of components around 1/4 from total 8192 entities | 4052 ns | 4052 ns | 171738
Select matching pairs of components around 1/4 from total 16384 entities | 8050 ns | 8049 ns | 85256
Select matching pairs of components around 1/4 from total 32768 entities | 15967 ns | 15965 ns | 43756
Select matching pairs of components around 1/4 from total 65536 entities | 31891 ns | 31888 ns | 21668
Select matching pairs of components around 1/4 from total 131072 entities | 64520 ns | 64515 ns | 10562
Select matching pairs of components around 1/4 from total 262144 entities | 134933 ns | 134919 ns | 5396
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 32831 ns | 32828 ns | 21221
Create and transfer entity without components to another entity manager | 36 ns | 36 ns | 20011535
Create and transfer entity with two components to another entity manager | 79 ns | 79 ns | 8968562
Create and transfer entity with two components to another entity manager (both have one index with both components) | 126 ns | 126 ns | 5677010

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 48.36
Iterate over matching pairs of components, around 1/4 from total **N** entities | N | 0.16
Select matching pairs of components around 1/4 from total **N** entities | N | 0.51
