cmake_minimum_required(VERSION 3.9)
project(nibbler)

set(CMAKE_CXX_STANDARD 11)

# Files paths

set(prefixSources project/sources/)
#set(prefixLib1 testLib1/sources/)
#set(prefixLib2 testLib2/sources/)
set(libDirectory ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# prepend path to files

FUNCTION(PREPEND var prefix)
    SET(listVar "")
    FOREACH(f ${ARGN})
        LIST(APPEND listVar "${prefix}/${f}")
    ENDFOREACH(f)
    SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

# sources

set(sourcesFiles
        main.cpp
        Map.cpp
        Bloc.cpp
        )

PREPEND(sourcesProject ${prefixSources} ${sourcesFiles})

# lib1

#set(lib1Files PartA.cpp PartB.cpp)

#PREPEND(sourcesLib1 ${prefixLib1} ${lib1Files})

# lib 2

#set(lib2Files PartA.cpp PartB.cpp)

#PREPEND(sourcesLib2 ${prefixLib2} ${lib2Files})

# libraries

#add_library(lib1 SHARED ${sourcesLib1})

#add_library(lib2 SHARED ${sourcesLib2})

# exe

add_executable(nibbler ${sourcesProject})

# add includes

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# set libs and executable properties

#set_target_properties(lib1 lib2 PROPERTIES
#        LIBRARY_OUTPUT_DIRECTORY ${libDirectory}
#        PREFIX ""
#        SUFFIX ".so")

set_target_properties(nibbler PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# links

#TARGET_LINK_LIBRARIES(nibbler lib1)

#TARGET_LINK_LIBRARIES(nibbler lib2)