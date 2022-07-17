2022-07-17T19:53:40+02:00  
Run on (4 X 2560 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 24.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 32.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 1024.0 KiB (x2)  
Load Average: 0.696289, 0.810059, 0.742188

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 233 ns | 233 ns | 2975624
Add one entity without components | 241 ns | 240 ns | 2629842
Add one entity with one component | 400 ns | 400 ns | 2120391
Add one entity with one component while having one index (the component is not in the index) | 396 ns | 396 ns | 2192119
Add one entity with one component while having one index (the component is in the index) | 474 ns | 474 ns | 1777252
Add one entity with 16 components | 3401 ns | 3401 ns | 231950
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 11416 ns | 11417 ns | 60873
Add one entity with 16 components while having 1 small index (the components are in the index) | 3660 ns | 3660 ns | 224144
Add one entity with 16 components while having 1 big index (the components are in the index) | 7000 ns | 7000 ns | 103493
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 11651 ns | 11652 ns | 55284
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 1521 ns | 1521 ns | 448474
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 4073 ns | 4074 ns | 172850
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 8108 ns | 8109 ns | 86475
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 16444 ns | 16446 ns | 43095
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 34149 ns | 34151 ns | 20480
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 89014 ns | 89016 ns | 9292
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 388875 ns | 388881 ns | 1806
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 819543 ns | 819439 ns | 854
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 1599399 ns | 1599470 ns | 432
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 402593 ns | 402548 ns | 1740
Select matching pairs of components around 1/4 from total 1024 entities | 1453 ns | 1453 ns | 479329
Select matching pairs of components around 1/4 from total 2048 entities | 3617 ns | 3617 ns | 193628
Select matching pairs of components around 1/4 from total 4096 entities | 8319 ns | 8319 ns | 99090
Select matching pairs of components around 1/4 from total 8192 entities | 13804 ns | 13804 ns | 49365
Select matching pairs of components around 1/4 from total 16384 entities | 27746 ns | 27748 ns | 21616
Select matching pairs of components around 1/4 from total 32768 entities | 56048 ns | 56044 ns | 12176
Select matching pairs of components around 1/4 from total 65536 entities | 303313 ns | 303289 ns | 2336
Select matching pairs of components around 1/4 from total 131072 entities | 700589 ns | 700552 ns | 986
Select matching pairs of components around 1/4 from total 262144 entities | 1355526 ns | 1355345 ns | 503
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 313149 ns | 313130 ns | 2329
Create and transfer entity without components to another entity manager | 398 ns | 397 ns | 1836189
Create and transfer entity with two components to another entity manager | 875 ns | 875 ns | 794131
Create and transfer entity with two components to another entity manager (both have one index with both components) | 1191 ns | 1191 ns | 592086

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 475.97
Iterate over matching pairs of components, around 1/4 from total **N** entities | NlgN | 0.34
Select matching pairs of components around 1/4 from total **N** entities | NlgN | 0.29
