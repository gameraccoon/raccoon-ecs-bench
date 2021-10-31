2021-10-31T14:51:10+01:00  
Run on (4 X 2561 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 24.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 32.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 1024.0 KiB (x2)  
Load Average: 1.74, 1.27, 1.02

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create empty entity manager | 189 ns | 189 ns | 3687456
Add one entity without components | 239 ns | 239 ns | 2643231
Add one entity with one component | 388 ns | 386 ns | 2021128
Add one entity with one component while having one index (the component not in the index) | 404 ns | 404 ns | 2204270
Add one entity with one component while having one index (the component in the index) | 465 ns | 465 ns | 1624274
Add one entity with 16 components | 3268 ns | 3257 ns | 243775
Add one entity with 16 components while having 8 indexes (the components not in the indexes) | 4557 ns | 4537 ns | 155182
Add one entity with 16 components while having 1 small index (the components in the index) | 3683 ns | 3682 ns | 225319
Add one entity with 16 components while having 1 big index (the components in the index) | 6591 ns | 6584 ns | 105212
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 11519 ns | 11518 ns | 59792
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 1634 ns | 1634 ns | 427514
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 4052 ns | 4052 ns | 172562
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 8082 ns | 8081 ns | 85462
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 16233 ns | 16179 ns | 42693
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 34097 ns | 34092 ns | 20471
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 103777 ns | 103763 ns | 5627
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 399869 ns | 399805 ns | 1867
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 799780 ns | 799523 ns | 870
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 1580697 ns | 1579567 ns | 444
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 391886 ns | 391774 ns | 1788
Select matching pairs of components around 1/4 from total 1024 entities | 1371 ns | 1366 ns | 512661
Select matching pairs of components around 1/4 from total 2048 entities | 3319 ns | 3319 ns | 208240
Select matching pairs of components around 1/4 from total 4096 entities | 6581 ns | 6579 ns | 105880
Select matching pairs of components around 1/4 from total 8192 entities | 12963 ns | 12960 ns | 54357
Select matching pairs of components around 1/4 from total 16384 entities | 25785 ns | 25692 ns | 27353
Select matching pairs of components around 1/4 from total 32768 entities | 61424 ns | 61417 ns | 11239
Select matching pairs of components around 1/4 from total 65536 entities | 254831 ns | 254790 ns | 2791
Select matching pairs of components around 1/4 from total 131072 entities | 659030 ns | 658502 ns | 1032
Select matching pairs of components around 1/4 from total 262144 entities | 1336463 ns | 1332489 ns | 495
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 308694 ns | 308610 ns | 2372
Create and transfer entity without components to another entity manager | 392 ns | 392 ns | 1861510
Create and transfer entity with two components to another entity manager | 866 ns | 865 ns | 823211
Create and transfer entity with two components to another entity manager (both have one index with both components) | 1185 ns | 1185 ns | 602711

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Iterate over matching pairs of components, around 1/4 from total **N** entities | NlgN | 0.34
Select matching pairs of components around 1/4 from total **N** entities | NlgN | 0.28
