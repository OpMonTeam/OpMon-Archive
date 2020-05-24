## Use clang-tidy if it is available
## and (by default) when we are in debug mode

set(USE_CLANG_TIDY ${DEBUG_BUILD} CACHE BOOL
    "Check code with clang-tidy")

if(${USE_CLANG_TIDY})

    message(CHECK_START "Looking for clang-tidy")

    find_program(CLANG_TIDY clang-tidy)

    if(CLANG_TIDY)
        message(CHECK_PASS "found ${CLANG_TIDY}")
        set_property(TARGET OpMon
            PROPERTY CXX_CLANG_TIDY ${CLANG_TIDY}
                -extra-arg=-Wno-unknown-warning-option)
    else()
        message(CHECK_FAIL "not found")
    endif()

    message(STATUS)
endif()

## Use cppcheck if it is available

set(USE_CPPCHECK FALSE CACHE BOOL
    "Check code with cppcheck")

if(${USE_CPPCHECK})

    message(CHECK_START "Looking for cppcheck")

    find_program(CPPCHECK cppcheck)

    if(CPPCHECK)
        message(CHECK_PASS "found ${CPPCHECK}")
        set_property(TARGET OpMon
            PROPERTY CXX_CPPCHECK ${CPPCHECK} --clang --language=c++
                --project=compile_commands.json --enable=all)
    else()
        message(CHECK_FAIL "not found")
    endif()

    message(STATUS)
endif()
