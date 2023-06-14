2023-06-14T15:49:53+02:00  
Run on (4 X 2560 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 24.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 32.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 1024.0 KiB (x2)  
Load Average: 0.274414, 0.578125, 1.4375

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 236 ns | 235 ns | 2961959
Add one entity without components | 254 ns | 254 ns | 2491624
Add one entity with one component | 376 ns | 376 ns | 1996456
Add one entity with one component while having one index (the component is not in the index) | 407 ns | 407 ns | 2199773
Add one entity with one component while having one index (the component is in the index) | 481 ns | 481 ns | 1613762
Add one entity with 16 components | 3157 ns | 3152 ns | 252983
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 4872 ns | 4870 ns | 144494
Add one entity with 16 components while having 1 small index (the components are in the index) | 3590 ns | 3587 ns | 229423
Add one entity with 16 components while having 1 big index (the components are in the index) | 7281 ns | 7270 ns | 97545
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 13132 ns | 13119 ns | 52661
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 878 ns | 877 ns | 792754
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 2067 ns | 2064 ns | 338936
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 5314 ns | 5309 ns | 133905
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 10200 ns | 10192 ns | 68259
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 20821 ns | 20795 ns | 33687
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 41351 ns | 41305 ns | 16827
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 95423 ns | 95339 ns | 7228
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 358737 ns | 358435 ns | 1972
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 771530 ns | 771031 ns | 838
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 99949 ns | 99833 ns | 7286
Select matching pairs of components around 1/4 from total 1024 entities | 962 ns | 961 ns | 723437
Select matching pairs of components around 1/4 from total 2048 entities | 2064 ns | 2063 ns | 338838
Select matching pairs of components around 1/4 from total 4096 entities | 4693 ns | 4687 ns | 136545
Select matching pairs of components around 1/4 from total 8192 entities | 8977 ns | 8967 ns | 77622
Select matching pairs of components around 1/4 from total 16384 entities | 18546 ns | 18526 ns | 38962
Select matching pairs of components around 1/4 from total 32768 entities | 35952 ns | 35905 ns | 17684
Select matching pairs of components around 1/4 from total 65536 entities | 83267 ns | 83214 ns | 9542
Select matching pairs of components around 1/4 from total 131072 entities | 180101 ns | 179942 ns | 3722
Select matching pairs of components around 1/4 from total 262144 entities | 529655 ns | 528887 ns | 1096
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 81529 ns | 81524 ns | 9069
Create and transfer entity without components to another entity manager | 396 ns | 395 ns | 1824589
Create and transfer entity with two components to another entity manager | 880 ns | 880 ns | 825194
Create and transfer entity with two components to another entity manager (both have one index with both components) | 1284 ns | 1282 ns | 565301

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 485.32
Iterate over matching pairs of components, around 1/4 from total **N** entities | NlgN | 0.16
Select matching pairs of components around 1/4 from total **N** entities | NlgN | 0.10
