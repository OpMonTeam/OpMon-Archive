set(NO_FETCH FALSE CACHE BOOL
    "Do not download and build dependencies")

if(${NO_FETCH})
    find_package(SFML 2.5.1 REQUIRED COMPONENTS
        graphics
        window
        system
        audio
        network)
else()

message(STATUS "Fetching dependencies")

include(FetchContent)

### SFML

message(STATUS "  SFML...")
message(STATUS)

list(APPEND CMAKE_MESSAGE_INDENT "        ")

FetchContent_Declare(sfml_ URL https://github.com/SFML/SFML/releases/download/2.5.1/SFML-2.5.1-sources.zip
                           URL_MD5 8533b22888102b4f0883311385fb1c71
                           )

set(BUILD_SHARED_LIBS OFF) #for static SFML
FetchContent_MakeAvailable(sfml_)

target_include_directories(OpMon SYSTEM PRIVATE ${sfml__SOURCE_DIR}/include)

target_link_libraries(sfml-graphics PUBLIC sanitizers)
target_link_libraries(sfml-window PUBLIC sanitizers)
target_link_libraries(sfml-system PUBLIC sanitizers)
target_link_libraries(sfml-audio PUBLIC sanitizers)
target_link_libraries(sfml-network PUBLIC sanitizers)

install(TARGETS sanitizers EXPORT SFMLConfigExport)

target_compile_definitions(sfml-audio PUBLIC -D_HAS_AUTO_PTR_ETC=1) #For Windows

list(POP_BACK CMAKE_MESSAGE_INDENT)

### JSON

message(STATUS "  json...")
message(STATUS)

FetchContent_Declare(json_ URL https://github.com/nlohmann/json/releases/download/v3.7.3/include.zip
                           URL_HASH SHA256=87b5884741427220d3a33df1363ae0e8b898099fbc59f1c451113f6732891014
                           )

FetchContent_Populate(json_)

target_include_directories(OpMon SYSTEM PRIVATE ${json__SOURCE_DIR}/include
                                                ${json__SOURCE_DIR}/include/nlohmann)
endif()

message(STATUS)

## Link to libraries

target_link_libraries(OpMon PRIVATE
    sanitizers
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network)
