## Enable as many compiler warnings as possible

set(WARNINGS_AS_ERRORS FALSE CACHE BOOL
    "Treat compiler warnings as errors")

if(WARNINGS_AS_ERRORS)
    message(VERBOSE "Warnings are being treated as errors")
    message(VERBOSE)
endif()

set(IGNORE_MOST_WARNINGS FALSE CACHE BOOL
    "Don't pass extra warning flags")

if(${COMPILING_WITH_CLANG} AND NOT ${IGNORE_MOST_WARNINGS})

    if(${WARNINGS_AS_ERRORS})
        target_compile_options(OpMon PRIVATE -Werror)
    endif()

    target_compile_options(OpMon PRIVATE -Wall -Wextra -Werror=pedantic
        -Wcast-align -Wcast-qual -Wconversion -Wdate-time -Wformat=2
        -Werror=main -Wold-style-cast -Werror=return-type -Wfloat-equal
        -Werror=zero-as-null-pointer-constant -Wmissing-noreturn
        -Wnon-virtual-dtor -Woverloaded-virtual -Wno-unknown-pragmas
        -Wabstract-vbase-init -Wcomma -Wduplicate-enum -Wempty-init-stmt
        -Wdeprecated -Werror=keyword-macro -Wundefined-reinterpret-cast
        -Wgcc-compat -Wheader-hygiene -Widiomatic-parentheses
        -Wimplicit-fallthrough -Wlogical-op-parentheses -Wloop-analysis
        -Wmismatched-tags -Wthread-safety -Wunreachable-code-aggressive)

elseif(${COMPILING_WITH_GCC} AND NOT ${IGNORE_MOST_WARNINGS})

    if(${WARNINGS_AS_ERRORS})
        target_compile_options(OpMon PRIVATE -Werror)
    endif()

    target_compile_options(OpMon PRIVATE -Wall -Wextra -Werror=pedantic
        -Wcast-align -Wcast-qual -Wconversion -Wdate-time -Wformat=2
        -Werror=main -Wold-style-cast -Werror=return-type -Wfloat-equal
        -Werror=zero-as-null-pointer-constant -Wmissing-noreturn
        -Wnon-virtual-dtor -Woverloaded-virtual -Wno-unknown-pragmas
        -Wduplicated-branches -Wduplicated-cond -pedantic-errors
        -Wimplicit-fallthrough=5 -Wlogical-op -Wnoexcept -Wnull-dereference
        -Wplacement-new=2 -Wsign-promo -Wsuggest-override -Wswitch-enum
        -Wuninitialized -Wuseless-cast -Wsuggest-final-types)

elseif(${COMPILING_WITH_MSVC} AND NOT ${IGNORE_MOST_WARNINGS})

    if(${WARNINGS_AS_ERRORS})
        target_compile_options(OpMon PRIVATE /Wx)
    endif()

    target_compile_options(/W4 /permissive- /w14640 /w14296)
endif()
