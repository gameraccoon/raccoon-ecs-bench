cmake_minimum_required(VERSION 3.16)
project(RaccoonEcsBenchmark)

set(CMAKE_CXX_STANDARD 20)
set(GAME_BASE_DIR ${CMAKE_SOURCE_DIR})
set(GOOGLE_BENCHMARK_DIR "${CMAKE_SOURCE_DIR}/../benchmark")
set(BIN_DIR "${GAME_BASE_DIR}/bin")

file(MAKE_DIRECTORY ${BIN_DIR})

if (MSVC)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG -DDEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
else()
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

include_directories(
        "${GOOGLE_BENCHMARK_DIR}/include"
        "${GOOGLE_BENCHMARK_DIR}/build/include"
	"raccoon-ecs"
)

set(SOURCES
	${GOOGLE_BENCHMARK_SRC}
	main.cpp
)

add_executable(RaccoonEcsBenchmark main.cpp ComponentsToBenchmark.h)

find_library(GOOGLE_BENCHMARK_LIB benchmark HINTS ${GOOGLE_BENCHMARK_DIR}/build/src)

target_link_libraries(RaccoonEcsBenchmark
	${GOOGLE_BENCHMARK_LIB}
	pthread
)

set_target_properties(RaccoonEcsBenchmark PROPERTIES
	EXPORT_NAME racoon-ecs-benchmark
	RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}"
)
