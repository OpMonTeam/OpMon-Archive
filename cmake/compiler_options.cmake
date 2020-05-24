## Detect if using a known compiler

set(COMPILING_WITH_CLANG FALSE)
set(COMPILING_WITH_GCC FALSE)
set(COMPILING_WITH_MSVC FALSE)

if(${CMAKE_CXX_COMPILER_ID} MATCHES ".*Clang")
    set(COMPILING_WITH_CLANG TRUE)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    set(COMPILING_WITH_GCC TRUE)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    set(COMPILING_WITH_MSVC TRUE)
endif()

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  Version: ${CMAKE_CXX_COMPILER_VERSION}")

message(STATUS)

## Set default build type

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                             "MinSizeRel" "RelWithDebInfo")
endif()

message(STATUS "${CMAKE_BUILD_TYPE} build")

message(STATUS)

set(DEBUG_BUILD FALSE)
set(RELEASE_BUILD FALSE)

if($<Config:Debug>)
    set(DEBUG_BUILD TRUE)
else()
    set(RELEASE_BUILD TRUE)
endif()

## Use IPO when available in release mode (by default)

set(USE_IPO ${RELEASE_BUILD} CACHE BOOL
    "Enable Interprocedural Optimization")

if(${USE_IPO})
    message(CHECK_START "Checking if IPO is supported")

    include(CheckIPOSupported)

    check_ipo_supported(RESULT ipo_supported OUTPUT output)

    if(ipo_supported)
        message(CHECK_PASS "yes")
        set_property(TARGET OpMon
                     PROPERTY CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
        message(CHECK_FAIL "IPO is not supported")
        message(VERBOSE "${output}")
    endif()

    message(STATUS)
endif()
