2022-01-12T22:55:37+01:00  
Run on (4 X 2560 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 24.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 32.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 1024.0 KiB (x2)  
Load Average: 0.36, 0.83, 0.94

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 189 ns | 189 ns | 3696103
Add one entity without components | 242 ns | 242 ns | 2617560
Add one entity with one component | 366 ns | 366 ns | 2058753
Add one entity with one component while having one index (the component is not in the index) | 394 ns | 394 ns | 2219590
Add one entity with one component while having one index (the component is in the index) | 491 ns | 491 ns | 1754600
Add one entity with 16 components | 3246 ns | 3246 ns | 242691
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 4438 ns | 4438 ns | 156188
Add one entity with 16 components while having 1 small index (the components are in the index) | 3601 ns | 3600 ns | 228028
Add one entity with 16 components while having 1 big index (the components are in the index) | 6695 ns | 6694 ns | 104681
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 11555 ns | 11552 ns | 60170
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 1727 ns | 1727 ns | 425287
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 4069 ns | 4068 ns | 171695
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 8069 ns | 8068 ns | 86395
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 16446 ns | 16444 ns | 42997
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 33972 ns | 33966 ns | 20635
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 75982 ns | 75950 ns | 8625
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 385824 ns | 385770 ns | 1820
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 809274 ns | 806447 ns | 898
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 1574376 ns | 1574097 ns | 443
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 394666 ns | 394598 ns | 1783
Select matching pairs of components around 1/4 from total 1024 entities | 1350 ns | 1350 ns | 514851
Select matching pairs of components around 1/4 from total 2048 entities | 3337 ns | 3337 ns | 208474
Select matching pairs of components around 1/4 from total 4096 entities | 6607 ns | 6606 ns | 105724
Select matching pairs of components around 1/4 from total 8192 entities | 12897 ns | 12849 ns | 54142
Select matching pairs of components around 1/4 from total 16384 entities | 25593 ns | 25589 ns | 27379
Select matching pairs of components around 1/4 from total 32768 entities | 59491 ns | 59484 ns | 13334
Select matching pairs of components around 1/4 from total 65536 entities | 287828 ns | 287789 ns | 2321
Select matching pairs of components around 1/4 from total 131072 entities | 662326 ns | 662274 ns | 1016
Select matching pairs of components around 1/4 from total 262144 entities | 1344938 ns | 1344581 ns | 510
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 316617 ns | 316587 ns | 2302
Create and transfer entity without components to another entity manager | 395 ns | 394 ns | 1855283
Create and transfer entity with two components to another entity manager | 871 ns | 871 ns | 809400
Create and transfer entity with two components to another entity manager (both have one index with both components) | 1191 ns | 1191 ns | 597925

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 475.95
Iterate over matching pairs of components, around 1/4 from total **N** entities | NlgN | 0.34
Select matching pairs of components around 1/4 from total **N** entities | NlgN | 0.28
