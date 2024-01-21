2024-01-21T22:41:12+01:00  
Run on (8 X 2424 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 64.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 128.0 KiB (x8)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 4096.0 KiB (x2)  
Load Average: 0.472656, 0.45752, 0.428223

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

### Benchmarks
Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create an empty entity manager | 23 ns | 23 ns | 31173314
Add one entity without components | 4 ns | 4 ns | 174991014
Add one entity with one component | 17 ns | 17 ns | 40032064
Add one entity with one component while having one index (the component is not in the index) | 17 ns | 17 ns | 40253251
Add one entity with one component while having one index (the component is in the index) | 28 ns | 28 ns | 24563587
Add one entity with 16 components | 292 ns | 292 ns | 2478642
Add one entity with 16 components while having 8 indexes (the components are not in the indexes) | 448 ns | 448 ns | 1540519
Add one entity with 16 components while having 1 small index (the components are in the index) | 296 ns | 296 ns | 2449004
Add one entity with 16 components while having 1 big index (the components are in the index) | 551 ns | 551 ns | 1163564
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 1090 ns | 1090 ns | 655300
Iterate over matching pairs of components, around 1/4 from total 1024 entities | 99 ns | 99 ns | 7024610
Iterate over matching pairs of components, around 1/4 from total 2048 entities | 201 ns | 201 ns | 3488958
Iterate over matching pairs of components, around 1/4 from total 4096 entities | 397 ns | 397 ns | 1768354
Iterate over matching pairs of components, around 1/4 from total 8192 entities | 781 ns | 781 ns | 865132
Iterate over matching pairs of components, around 1/4 from total 16384 entities | 2775 ns | 2775 ns | 254648
Iterate over matching pairs of components, around 1/4 from total 32768 entities | 5367 ns | 5367 ns | 129208
Iterate over matching pairs of components, around 1/4 from total 65536 entities | 10532 ns | 10532 ns | 66420
Iterate over matching pairs of components, around 1/4 from total 131072 entities | 20871 ns | 20870 ns | 33552
Iterate over matching pairs of components, around 1/4 from total 262144 entities | 42082 ns | 42081 ns | 16625
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 11144 ns | 11144 ns | 63047
Select matching pairs of components around 1/4 from total 1024 entities | 473 ns | 473 ns | 1478205
Select matching pairs of components around 1/4 from total 2048 entities | 1045 ns | 1045 ns | 667881
Select matching pairs of components around 1/4 from total 4096 entities | 2085 ns | 2085 ns | 335065
Select matching pairs of components around 1/4 from total 8192 entities | 4129 ns | 4129 ns | 168325
Select matching pairs of components around 1/4 from total 16384 entities | 8283 ns | 8283 ns | 84179
Select matching pairs of components around 1/4 from total 32768 entities | 16564 ns | 16564 ns | 41827
Select matching pairs of components around 1/4 from total 65536 entities | 33306 ns | 33306 ns | 20991
Select matching pairs of components around 1/4 from total 131072 entities | 67404 ns | 67403 ns | 10225
Select matching pairs of components around 1/4 from total 262144 entities | 135470 ns | 135467 ns | 5076
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 32803 ns | 32802 ns | 21074
Create and transfer entity without components to another entity manager | 10 ns | 10 ns | 70026464
Create and transfer entity with two components to another entity manager | 53 ns | 53 ns | 13255254
Create and transfer entity with two components to another entity manager (both have one index with both components) | 95 ns | 95 ns | 7492728

### BigO Complexities
Benchmark | Complexity | Coefficient
--- | --- | ---
Create an entity manager, add one index and **N** entities with one component each (the component is in the index) | N | 23.58
Iterate over matching pairs of components, around 1/4 from total **N** entities | N | 0.16
Select matching pairs of components around 1/4 from total **N** entities | N | 0.52
