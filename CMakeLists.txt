cmake_minimum_required(VERSION 3.17)
set(CMAKE_ERROR_DEPRECATED TRUE)

## General system information

message(VERBOSE
    "CMake version is ${CMAKE_VERSION}")

message(VERBOSE
    "  CMake root directory is '${CMAKE_ROOT}'")

message(VERBOSE
    "Generator is '${CMAKE_GENERATOR}'")

message(VERBOSE) #outputs a newline

## Set up project

project(OpMon
    VERSION 0.16.0
    DESCRIPTION "An open source RPG monster fighting game"
    HOMEPAGE_URL "http://opmon-game.ga/"
    LANGUAGES C CXX)

message(STATUS)

message(STATUS
    "Configuring ${PROJECT_NAME} "
    "${${PROJECT_NAME}_VERSION}")

message(VERBOSE
    "  Source directory is '${CMAKE_SOURCE_DIR}'")

message(VERBOSE
    "  Build directory is '${CMAKE_BINARY_DIR}'")

message(STATUS)

## Set the required C++ standard to C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(VERBOSE
    "Using C++${CMAKE_CXX_STANDARD} mode")

message(VERBOSE)

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

## Generate compilation database

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE CACHE BOOL
    "Export compile_commands.json" FORCE)

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

## Use clang-tidy if it is available
## and (by default) when we are in debug mode

set(USE_CLANG_TIDY ${DEBUG_BUILD} CACHE BOOL
    "Check code with clang-tidy")

if(${USE_CLANG_TIDY})

    message(CHECK_START "Looking for clang-tidy")

    find_program(CLANG_TIDY clang-tidy)

    if(CLANG_TIDY)
        message(CHECK_PASS "found ${CLANG_TIDY}")
        set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY})
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
        set(CMAKE_CXX_CPPCHECK ${CPPCHECK} -i lib/ --project=compile_commands.json --enable=missingInclude,performance,portability)
    else()
        message(CHECK_FAIL "not found")
    endif()

    message(STATUS)
endif()

## Add main target

add_executable(OpMon)

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

## Build SFML

message(STATUS)

message(STATUS "Adding SFML")

message(STATUS)

set(BUILD_SHARED_LIBS OFF) #for static SFML
set(SFML_INSTALL_PKGCONFIG_FILES OFF)
set(SFML_INSTALL_XCODE_TEMPLATES OFF)
add_subdirectory(lib/SFML EXCLUDE_FROM_ALL)

target_link_libraries(sfml-graphics PUBLIC sanitizers)
target_link_libraries(sfml-window PUBLIC sanitizers)
target_link_libraries(sfml-system PUBLIC sanitizers)
target_link_libraries(sfml-audio PUBLIC sanitizers)
target_link_libraries(sfml-network PUBLIC sanitizers)

install(TARGETS sanitizers EXPORT SFMLConfigExport)

target_include_directories(OpMon SYSTEM PRIVATE lib/SFML/include)

#For Windows
target_compile_definitions(sfml-audio PUBLIC -D_HAS_AUTO_PTR_ETC=1)

## Build fmt

message(STATUS)

message(STATUS "Adding fmt")

message(STATUS)

add_subdirectory(lib/fmt)

target_link_libraries(fmt PUBLIC sanitizers)

target_include_directories(OpMon SYSTEM PRIVATE lib/fmt/include)

## Build spdlog

message(STATUS)

message(STATUS "Adding spdlog")

message(STATUS)

add_subdirectory(lib/spdlog)

target_link_libraries(spdlog PUBLIC sanitizers)

target_include_directories(OpMon SYSTEM PRIVATE lib/spdlog/include)

## Link to libraries

target_link_libraries(OpMon PRIVATE
    sanitizers
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
    fmt
    spdlog)

## Deal with header only libraries

target_include_directories(OpMon SYSTEM PRIVATE lib/tomlpp)
target_compile_definitions(OpMon PRIVATE -DTOML_ALL_INLINE=0 TOML_EXCEPTIONS=0)
target_sources(OpMon PRIVATE lib/tomlpp/toml_imp.cpp)

target_include_directories(OpMon SYSTEM PRIVATE lib/json)

## Include paths for the game code

target_include_directories(OpMon PRIVATE src)

## Add the game's source files

target_sources(OpMon PRIVATE
    src/AbstractEvent.cpp src/AbstractEvent.hpp
    src/AbstractMetaEvent.cpp src/AbstractMetaEvent.hpp
    src/AGameScreen.hpp
    src/AnimationCtrl.cpp src/AnimationCtrl.hpp
    src/AnimationEvent.cpp src/AnimationEvent.hpp
    src/Animations.cpp src/Animations.hpp
    src/ATranslatable.cpp src/ATranslatable.hpp
    src/Battle.cpp
    src/BattleCtrl.cpp src/BattleCtrl.hpp
    src/BattleData.cpp src/BattleData.hpp
    src/BattleEvent.cpp src/BattleEvent.hpp
    src/Battle.hpp
    src/centerOrigin.hpp
    src/CharacterEvent.cpp src/CharacterEvent.hpp
    src/CurveExp.cpp src/CurveExp.hpp
    src/CycleCounter.hpp
    src/defines.hpp
    src/Dialog.cpp src/Dialog.hpp
    src/DialogEvent.cpp src/DialogEvent.hpp
    src/EItem.cpp
    src/Elements.cpp src/Elements.hpp
    src/ELevel.cpp
    src/Enums.cpp src/Enums.hpp
    src/Evolution.cpp src/Evolution.hpp
    src/evolutions.hpp
    src/exceptions.cpp src/exceptions.hpp
    src/fs.cpp src/fs.hpp
    src/GameData.cpp src/GameData.hpp
    src/Gameloop.cpp src/Gameloop.hpp
    src/GameMenu.cpp
    src/GameMenuCtrl.cpp src/GameMenuCtrl.hpp
    src/GameMenuData.cpp src/GameMenuData.hpp
    src/GameMenu.hpp
    src/GameStatus.hpp
    src/IntroScene.cpp
    src/IntroSceneCtrl.cpp src/IntroSceneCtrl.hpp
    src/IntroSceneData.cpp src/IntroSceneData.hpp
    src/IntroScene.hpp
    src/Item.cpp src/Item.hpp
    src/Jukebox.cpp src/Jukebox.hpp
    src/Keyboard.cpp src/Keyboard.hpp
    src/LinearMetaEvent.cpp src/LinearMetaEvent.hpp
    src/log.cpp src/log.hpp
    src/main.cpp
    src/MainMenu.cpp
    src/MainMenuCtrl.cpp src/MainMenuCtrl.hpp
    src/MainMenuData.cpp src/MainMenuData.hpp
    src/MainMenu.hpp
    src/Map.cpp src/Map.hpp
    src/metaevents.cpp src/metaevents.hpp
    src/misc.cpp src/misc.hpp
    src/Move.cpp src/Move.hpp
    src/Moves.cpp src/Moves.hpp
    src/Nature.cpp src/Nature.hpp
    src/OpMon.cpp src/OpMon.hpp
    src/OpString.cpp src/OpString.hpp
    src/OpTeam.cpp src/OpTeam.hpp
    src/OptionsMenu.cpp
    src/OptionsMenuCtrl.cpp src/OptionsMenuCtrl.hpp
    src/OptionsMenuData.cpp src/OptionsMenuData.hpp
    src/OptionsMenu.hpp
    src/OptionsSave.cpp src/OptionsSave.hpp
    src/Overworld.cpp
    src/OverworldCtrl.cpp src/OverworldCtrl.hpp
    src/OverworldData.cpp src/OverworldData.hpp
    src/Overworld.hpp
    src/path.cpp src/path.hpp
    src/Player.cpp src/Player.hpp
    src/Position.cpp src/Position.hpp
    src/ResourceLoader.cpp src/ResourceLoader.hpp
    src/SaveMenu.cpp
    src/SaveMenuCtrl.cpp src/SaveMenuCtrl.hpp
    src/SaveMenuData.cpp src/SaveMenuData.hpp
    src/SaveMenu.hpp
    src/SoundEvent.cpp src/SoundEvent.hpp
    src/Species.cpp src/Species.hpp
    src/StringKeys.cpp src/StringKeys.hpp
    src/TextBox.cpp src/TextBox.hpp
    src/time.cpp src/time.hpp
    src/TPEvent.cpp src/TPEvent.hpp
    src/Translator.cpp src/Translator.hpp
    src/Turn.cpp src/Turn.hpp
    src/Window.cpp src/Window.hpp)

## Windows specific

if(WIN32)
    set_property(TARGET OpMon PROPERTY WIN32_EXECUTABLE TRUE)
    target_sources(OpMon PRIVATE resources.rc)
endif()

###### TODO: INSTALL correctly

## Install

if(UNIX)
    install(TARGETS OpMon DESTINATION bin)
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/OpMon-Data/GameData/OPMon.desktop DESTINATION share/applications)

    # TODO: put resource files in the correct folder
    # Note: trailing slash "bin/" is important.
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/OpMon-Data/GameData/ DESTINATION share/OpMon)
else()
    install(TARGETS OpMon DESTINATION .)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/OpMon-Data/GameData DESTINATION .)
endif()

## Cpack

include(CPack)

set(CPACK_GENERATOR "TGZ;DEB")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_CONTACT "Cyrielle <cyriellecentori@uymail.com>")
set(CPACK_DEBIAN_PACKAGE_SECTION "games")
