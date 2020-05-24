## Enable sanitizers in GCC and Clang.
## Address, Undefined, and Leak sanitizers are
## enabled by default in debug mode

add_library(sanitizers INTERFACE)

if(${COMPILING_WITH_GCC} OR ${COMPILING_WITH_CLANG})
    set(USE_ADDRESS_SANITIZER ${DEBUG_BUILD} CACHE BOOL
        "Use address sanitizer")

    set(USE_THREAD_SANITIZER FALSE CACHE BOOL
        "Use thread sanitizer")

    set(USE_MEMORY_SANITIZER FALSE CACHE BOOL
        "Use memory sanitizer")

    set(USE_UNDEFINED_SANITIZER ${DEBUG_BUILD} CACHE BOOL
        "Use undefined behavior sanitizer")

    set(USE_LEAK_SANITIZER ${DEBUG_BUILD} CACHE BOOL
        "Use leak sanitizer")

    if(${USE_ADDRESS_SANITIZER})
        message(VERBOSE "Using address sanitizer")
        target_compile_options(sanitizers INTERFACE -fsanitize=address)
        target_link_libraries(sanitizers INTERFACE -fsanitize=address)
    endif()

    if(${USE_THREAD_SANITIZER})
        message(VERBOSE "Using thread sanitizer")
        target_compile_options(sanitizers INTERFACE -fsanitize=thread)
        target_link_libraries(sanitizers INTERFACE -fsanitize=thread)
    endif()

    if(${USE_MEMORY_SANITIZER})
        message(VERBOSE "Using memory sanitizer")
        target_compile_options(sanitizers INTERFACE -fsanitize=memory)
        target_link_libraries(sanitizers INTERFACE -fsanitize=memory)
    endif()

    if(${USE_UNDEFINED_SANITIZER})
        message(VERBOSE "Using undefined behavior sanitizer")
        target_compile_options(sanitizers INTERFACE -fsanitize=undefined)
        target_link_libraries(sanitizers INTERFACE -fsanitize=undefined)
    endif()

    if(${USE_LEAK_SANITIZER})
        message(VERBOSE "Using leak sanitizer")
        target_compile_options(sanitizers INTERFACE -fsanitize=leak)
        target_link_libraries(sanitizers INTERFACE -fsanitize=leak)
    endif()
endif()
