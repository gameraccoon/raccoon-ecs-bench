2023-12-06T00:00:15+01:00  
Run on (8 X 2424 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 64.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 128.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 4096.0 KiB (x2)  
Load Average: 0.241211, 0.548828, 0.655273

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 24 ns | 24 ns | 29452076
Add one entity without components | 21 ns | 21 ns | 35378171
Add one entity with one component | 33 ns | 33 ns | 24675734
Add one entity with one component while having one index (the component is not in the index) | 30 ns | 30 ns | 24557842
Add one entity with one component while having one index (the component is in the index) | 41 ns | 41 ns | 17968260
Add one entity with 16 components | 275 ns | 275 ns | 2683672
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 438 ns | 438 ns | 1591004
Add one entity with 16 components while having 1 small index (the components are in the index) | 287 ns | 287 ns | 2581020
Add one entity with 16 components while having 1 big index (the components are in the index) | 531 ns | 531 ns | 1311281
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 991 ns | 991 ns | 703857
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 95 ns | 95 ns | 7178993
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 197 ns | 197 ns | 3533721
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 385 ns | 385 ns | 1801463
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 762 ns | 762 ns | 884138
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 2755 ns | 2755 ns | 225536
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 5165 ns | 5165 ns | 128300
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 10300 ns | 10299 ns | 67258
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 20252 ns | 20250 ns | 34790
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 41059 ns | 41054 ns | 17168
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 10784 ns | 10782 ns | 63493
Select matching pairs of components around 1/4 from total 1024 entities | 459 ns | 459 ns | 1522266
Select matching pairs of components around 1/4 from total 2048 entities | 1009 ns | 1009 ns | 677290
Select matching pairs of components around 1/4 from total 4096 entities | 2025 ns | 2025 ns | 342096
Select matching pairs of components around 1/4 from total 8192 entities | 4014 ns | 4013 ns | 173898
Select matching pairs of components around 1/4 from total 16384 entities | 8032 ns | 8031 ns | 86472
Select matching pairs of components around 1/4 from total 32768 entities | 16165 ns | 16164 ns | 42722
Select matching pairs of components around 1/4 from total 65536 entities | 32389 ns | 32386 ns | 21677
Select matching pairs of components around 1/4 from total 131072 entities | 65044 ns | 65039 ns | 10649
Select matching pairs of components around 1/4 from total 262144 entities | 131052 ns | 131041 ns | 5215
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 31818 ns | 31812 ns | 21806
Create and transfer entity without components to another entity manager | 35 ns | 34 ns | 20291151
Create and transfer entity with two components to another entity manager | 77 ns | 77 ns | 9090073
Create and transfer entity with two components to another entity manager (both have one index with both components) | 123 ns | 123 ns | 5786630

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 47.37
Iterate over matching pairs of components, around 1/4 from total **N** entities | N | 0.16
Select matching pairs of components around 1/4 from total **N** entities | N | 0.50
