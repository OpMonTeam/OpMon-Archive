## Globally set the required standard to C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(VERBOSE
    "Using C++${CMAKE_CXX_STANDARD} mode")

message(VERBOSE)

## Use ccache if it is available

message(CHECK_START "Looking for ccache")

find_program(CCACHE ccache)

if(CCACHE)
    message(CHECK_PASS "found ${CCACHE}")
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
else()
    message(CHECK_FAIL "not found")
endif()

message(STATUS)

## Generate compilation database

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE CACHE BOOL
    "Export compile_commands.json" FORCE)
