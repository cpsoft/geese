cmake_minimum_required(VERSION 2.8)
PROJECT(geese)
include(UsePkgConfig)
set(target geese)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(${CMAKE_SOURCE_DIR} SRC)
message(${SRC})
add_executable(${target} ${SRC})

PkgConfig(libxml-2.0 includedir libdir linkflags cflags)
include_directories(${includedir})
link_directories(${libdir})
target_link_libraries(${target} ${linkflags})
add_definitions(${cflags})


PkgConfig(vg includedir libdir linkflags cflags)
include_directories(${includedir})
link_directories(${libdir})
target_link_libraries(${target} ${linkflags} -lglut -lGL -lGLU )
add_definitions(${cflags})



add_definitions("-DDEBUG")
