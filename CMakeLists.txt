cmake_minimum_required(VERSION 3.17)

cmake_policy(SET CMP0077 NEW)

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

include(cmake/globals.cmake)

message(STATUS
    "Configuring ${PROJECT_NAME} "
    "${${PROJECT_NAME}_VERSION}")

message(VERBOSE
    "  Source directory is '${PROJECT_SOURCE_DIR}'")

message(VERBOSE
    "  Build directory is '${PROJECT_BINARY_DIR}'")

message(STATUS)

## Add game target

add_executable(${PROJECT_NAME})

include(cmake/compiler_options.cmake)
include(cmake/analysis.cmake)
include(cmake/compiler_warnings.cmake)
include(cmake/sanitize.cmake)
include(cmake/dependencies.cmake)

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
