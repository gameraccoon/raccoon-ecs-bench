cmake_minimum_required(VERSION 3.19)
project(simple_movement)

set(CMAKE_CXX_STANDARD 20)
set(GOOGLE_BENCHMARK_DIR "../../../benchmark")

include_directories(
	"${GOOGLE_BENCHMARK_DIR}/include"
	"../../raccoon-ecs"
)

set(SOURCES
	${GOOGLE_BENCHMARK_SRC}
	main.cpp
)

add_executable(simple_movement main.cpp ComponentsToBenchmark.h)

find_library(GOOGLE_BENCHMARK_LIB benchmark HINTS ${GOOGLE_BENCHMARK_DIR}/build/src)

target_link_libraries(simple_movement
	${GOOGLE_BENCHMARK_LIB}
	pthread
)

