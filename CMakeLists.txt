cmake_minimum_required(VERSION 3.9)
project(NiBBer)

set(prefixSources sources/)
set(prefixLib1 libtest1/)
set(prefixLib2 libtest2/)

FUNCTION(PREPEND var prefix)
    SET(listVar "")
    FOREACH(f ${ARGN})
        LIST(APPEND listVar "${prefix}/${f}")
    ENDFOREACH(f)
    SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

set(CMAKE_CXX_STANDARD 11)

set(sourcesFiles main.cpp)
PREPEND(sources ${prefixSources} ${sourcesFiles})

set(lib1Files TestA.cpp TestB.cpp)
PREPEND(sourcesLib1 ${prefixLib1} ${lib1Files})

set(lib2Files TestA.cpp TestB.cpp)
PREPEND(sourcesLib2 ${prefixLib2} ${lib2Files})

add_library(lib1 SHARED ${sourcesLib1})
add_library(lib2 SHARED ${sourcesLib2})
add_executable(nibbler ${sources})

set_target_properties(lib1 lib2 PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY    ${CMAKE_CURRENT_SOURCE_DIR}/libs
        PREFIX                      ""
        SUFFIX                      ".so")

set_target_properties(nibbler PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

TARGET_LINK_LIBRARIES(nibbler lib1)
TARGET_LINK_LIBRARIES(nibbler lib2)