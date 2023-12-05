cmake_minimum_required(VERSION 3.16)
project(RaccoonEcsBenchmark)

set(CMAKE_CXX_STANDARD 20)
set(GAME_BASE_DIR ${CMAKE_SOURCE_DIR})
set(BIN_DIR "${GAME_BASE_DIR}/bin")

file(MAKE_DIRECTORY ${BIN_DIR})

if (MSVC)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG -DDEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
else()
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

set(BENCHMARK_ENABLE_TESTING FALSE)
add_subdirectory(benchmark)

include_directories(
	"raccoon-ecs"
)

set(SOURCES
	main.cpp
)

add_executable(RaccoonEcsBenchmark main.cpp ComponentsToBenchmark.h)

target_link_libraries(RaccoonEcsBenchmark
	benchmark::benchmark
	pthread
)

set_target_properties(RaccoonEcsBenchmark PROPERTIES
	EXPORT_NAME racoon-ecs-benchmark
	RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}"
)
