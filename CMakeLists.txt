cmake_minimum_required(VERSION 3.3.0)
project(OpMon)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

#				<Option output="exeLinux/OpMon-Debug" />
#				<Option working_dir="exeLinux/" />
#				<Option object_output="obj/Debug/" />

set(CMAKE_DEBUG_POSTFIX "Debug")

# list all .cpp files in src/
# .hpp are handled automatically.
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)



# Note: the executable must be declared before adding libraries
add_executable(OpMon ${SOURCE_FILES})


if (WIN32)
    list(APPEND SOURCE_FILES resources.rc)
endif()


# Set the folder where to find cmake modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Add SFML
find_package(SFML COMPONENTS graphics window system audio)
target_link_libraries(OpMon ${SFML_LIBRARIES})
