2021-10-31T15:50:07+01:00  
Run on (4 X 1858 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 24.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 32.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 1024.0 KiB (x2)  
Load Average: 1.22, 1.27, 1.26

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 189 ns | 189 ns | 3705086
Add one entity without components | 238 ns | 238 ns | 2644434
Add one entity with one component | 364 ns | 363 ns | 2063524
Add one entity with one component while having one index (the component is not in the index) | 391 ns | 391 ns | 2228069
Add one entity with one component while having one index (the component is in the index) | 478 ns | 478 ns | 1760290
Add one entity with 16 components | 3330 ns | 3330 ns | 239788
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 4446 ns | 4445 ns | 155394
Add one entity with 16 components while having 1 small index (the components are in the index) | 3571 ns | 3570 ns | 225900
Add one entity with 16 components while having 1 big index (the components are in the index) | 6683 ns | 6683 ns | 104217
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 11554 ns | 11554 ns | 59949
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 1627 ns | 1627 ns | 438315
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 4068 ns | 4068 ns | 171678
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 8164 ns | 8164 ns | 85397
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 16501 ns | 16499 ns | 43275
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 34162 ns | 34148 ns | 20508
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 72259 ns | 72210 ns | 9226
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 371722 ns | 371680 ns | 1793
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 787432 ns | 785414 ns | 897
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 1580460 ns | 1579839 ns | 436
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 405326 ns | 405096 ns | 1770
Select matching pairs of components around 1/4 from total 1024 entities | 1348 ns | 1348 ns | 515142
Select matching pairs of components around 1/4 from total 2048 entities | 3355 ns | 3354 ns | 210931
Select matching pairs of components around 1/4 from total 4096 entities | 6603 ns | 6602 ns | 105578
Select matching pairs of components around 1/4 from total 8192 entities | 12874 ns | 12869 ns | 54175
Select matching pairs of components around 1/4 from total 16384 entities | 35011 ns | 34998 ns | 27395
Select matching pairs of components around 1/4 from total 32768 entities | 52127 ns | 52115 ns | 13257
Select matching pairs of components around 1/4 from total 65536 entities | 317028 ns | 316940 ns | 2353
Select matching pairs of components around 1/4 from total 131072 entities | 685516 ns | 685373 ns | 1005
Select matching pairs of components around 1/4 from total 262144 entities | 1327545 ns | 1326612 ns | 504
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 324556 ns | 324381 ns | 2369
Create and transfer entity without components to another entity manager | 394 ns | 394 ns | 1862410
Create and transfer entity with two components to another entity manager | 885 ns | 884 ns | 812966
Create and transfer entity with two components to another entity manager (both have one index with both components) | 1184 ns | 1183 ns | 607899

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 471.21
Iterate over matching pairs of components, around 1/4 from total **N** entities | NlgN | 0.34
Select matching pairs of components around 1/4 from total **N** entities | NlgN | 0.28
