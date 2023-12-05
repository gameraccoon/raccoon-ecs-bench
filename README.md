2023-12-05T21:25:56+01:00  
Run on (8 X 2424 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 64.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 128.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 4096.0 KiB (x2)  
Load Average: 0.229492, 0.42334, 0.478027

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 24 ns | 24 ns | 28843108
Add one entity without components | 21 ns | 21 ns | 33940992
Add one entity with one component | 33 ns | 33 ns | 24808670
Add one entity with one component while having one index (the component is not in the index) | 30 ns | 30 ns | 24534108
Add one entity with one component while having one index (the component is in the index) | 42 ns | 42 ns | 17993375
Add one entity with 16 components | 278 ns | 278 ns | 2668535
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 443 ns | 443 ns | 1556407
Add one entity with 16 components while having 1 small index (the components are in the index) | 288 ns | 288 ns | 2587425
Add one entity with 16 components while having 1 big index (the components are in the index) | 527 ns | 527 ns | 1282859
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 991 ns | 991 ns | 697523
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 95 ns | 95 ns | 6998711
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 196 ns | 196 ns | 3519183
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 387 ns | 387 ns | 1816515
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 756 ns | 756 ns | 905806
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 2854 ns | 2853 ns | 257998
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 5259 ns | 5258 ns | 130681
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 10156 ns | 10154 ns | 68042
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 20471 ns | 20468 ns | 34026
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 40976 ns | 40969 ns | 16842
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 11036 ns | 11035 ns | 62590
Select matching pairs of components around 1/4 from total 1024 entities | 463 ns | 463 ns | 1514691
Select matching pairs of components around 1/4 from total 2048 entities | 1015 ns | 1014 ns | 673907
Select matching pairs of components around 1/4 from total 4096 entities | 2029 ns | 2028 ns | 338074
Select matching pairs of components around 1/4 from total 8192 entities | 4005 ns | 4005 ns | 173267
Select matching pairs of components around 1/4 from total 16384 entities | 7967 ns | 7966 ns | 83736
Select matching pairs of components around 1/4 from total 32768 entities | 16181 ns | 16179 ns | 43167
Select matching pairs of components around 1/4 from total 65536 entities | 32128 ns | 32123 ns | 21557
Select matching pairs of components around 1/4 from total 131072 entities | 64614 ns | 64605 ns | 10431
Select matching pairs of components around 1/4 from total 262144 entities | 129853 ns | 129834 ns | 5200
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 31521 ns | 31516 ns | 21906
Create and transfer entity without components to another entity manager | 34 ns | 34 ns | 20472106
Create and transfer entity with two components to another entity manager | 76 ns | 76 ns | 9082068
Create and transfer entity with two components to another entity manager (both have one index with both components) | 123 ns | 123 ns | 5699154

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 47.21
Iterate over matching pairs of components, around 1/4 from total **N** entities | N | 0.16
Select matching pairs of components around 1/4 from total **N** entities | N | 0.49
