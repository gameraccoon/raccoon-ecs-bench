2023-12-05T21:23:26+01:00  
Run on (8 X 2424 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 64.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 128.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 4096.0 KiB (x2)  
Load Average: 0.343262, 0.473145, 0.495605

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 24 ns | 24 ns | 28628501
Add one entity without components | 21 ns | 21 ns | 34077232
Add one entity with one component | 30 ns | 30 ns | 24422644
Add one entity with one component while having one index (the component is not in the index) | 30 ns | 30 ns | 24170839
Add one entity with one component while having one index (the component is in the index) | 42 ns | 42 ns | 18172653
Add one entity with 16 components | 277 ns | 277 ns | 2660204
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 435 ns | 435 ns | 1585046
Add one entity with 16 components while having 1 small index (the components are in the index) | 288 ns | 288 ns | 2560575
Add one entity with 16 components while having 1 big index (the components are in the index) | 525 ns | 525 ns | 1302095
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 1017 ns | 1017 ns | 694095
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 96 ns | 96 ns | 7103654
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 199 ns | 199 ns | 3505578
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 388 ns | 388 ns | 1818116
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 759 ns | 759 ns | 921142
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 2778 ns | 2778 ns | 238829
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 5321 ns | 5321 ns | 128501
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 10324 ns | 10323 ns | 67571
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 20411 ns | 20409 ns | 34455
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 41206 ns | 41202 ns | 17106
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 10841 ns | 10841 ns | 65161
Select matching pairs of components around 1/4 from total 1024 entities | 463 ns | 463 ns | 1520237
Select matching pairs of components around 1/4 from total 2048 entities | 1018 ns | 1018 ns | 687554
Select matching pairs of components around 1/4 from total 4096 entities | 2036 ns | 2036 ns | 340417
Select matching pairs of components around 1/4 from total 8192 entities | 4022 ns | 4021 ns | 173920
Select matching pairs of components around 1/4 from total 16384 entities | 8048 ns | 8048 ns | 86138
Select matching pairs of components around 1/4 from total 32768 entities | 16542 ns | 16541 ns | 42756
Select matching pairs of components around 1/4 from total 65536 entities | 32612 ns | 32610 ns | 21111
Select matching pairs of components around 1/4 from total 131072 entities | 65173 ns | 65168 ns | 10470
Select matching pairs of components around 1/4 from total 262144 entities | 131558 ns | 131547 ns | 5157
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 32184 ns | 32182 ns | 21665
Create and transfer entity without components to another entity manager | 35 ns | 35 ns | 20272467
Create and transfer entity with two components to another entity manager | 77 ns | 76 ns | 9054495
Create and transfer entity with two components to another entity manager (both have one index with both components) | 123 ns | 123 ns | 5804163

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 47.62
Iterate over matching pairs of components, around 1/4 from total **N** entities | N | 0.16
Select matching pairs of components around 1/4 from total **N** entities | N | 0.50
