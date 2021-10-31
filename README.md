2021-10-31T11:42:33+01:00  
Run on (4 X 2560 MHz CPU s)  
CPU Caches:  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Data 24.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L1 Instruction 32.0 KiB (x4)  
&nbsp;&nbsp;&nbsp;&nbsp;L2 Unified 1024.0 KiB (x2)  
Load Average: 0.43, 0.7, 0.77

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

Benchmark | Time | CPU | Iterations
--- | --- | --- | ---
Create empty entity manager | 189 ns | 189 ns | 3661629
Add one entity without components | 240 ns | 240 ns | 2647549
Add one entity with one component | 364 ns | 364 ns | 2060151
Add one entity with one component while having one index (the component not in the index) | 394 ns | 392 ns | 2233130
Add one entity with one component while having one index (the component in the index) | 470 ns | 470 ns | 1800064
Add one entity with 16 components | 3249 ns | 3246 ns | 245218
Add one entity with 16 components while having 8 indexes (the components not in the indexes) | 4368 ns | 4366 ns | 158865
Add one entity with 16 components while having 1 small index (the components in the index) | 3497 ns | 3496 ns | 231606
Add one entity with 16 components while having 1 big index (the components in the index) | 6584 ns | 6583 ns | 105075
Add one entity with 16 components while having 8 different index (the components are in the indexes) | 11506 ns | 11503 ns | 60400
Iterate over matching pairs of components (around 1000) from 4000 entities | 7881 ns | 7853 ns | 87948
Iterate over matching pairs of components (around 2000) from 8000 entities | 15940 ns | 15939 ns | 44432
Iterate over matching pairs of components (around 4000) from 16000 entities | 33286 ns | 33280 ns | 20996
Iterate over matching pairs of components (around 8000) from 32000 entities | 89662 ns | 89647 ns | 7820
Iterate over matching pairs of components (around 16000) from 64000 entities | 372684 ns | 371112 ns | 1883
Iterate over matching pairs of components (around 32000) from 128000 entities | 770613 ns | 770438 ns | 914
Iterate over matching pairs of components (around 64000) from 256000 entities | 1559692 ns | 1559615 ns | 442
Iterate over matching pairs of components (around 128000) from 512000 entities | 3056204 ns | 3055853 ns | 230
Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 411409 ns | 409534 ns | 1785
Select matching pairs of components (around 1000) from 4000 entities | 6441 ns | 6435 ns | 107450
Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each | 312887 ns | 312698 ns | 2212
Create and transfer entity without components to another entity manager | 394 ns | 393 ns | 1856947
Create and transfer entity with two components to another entity manager | 868 ns | 867 ns | 811132
Create and transfer entity with two components to another entity manager (both have one index with both components) | 1195 ns | 1190 ns | 605930
