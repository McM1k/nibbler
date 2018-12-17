cmake_minimum_required(VERSION 3.9)
project(nibbler)

set(CMAKE_CXX_STANDARD 11)

# Files paths

set(prefixSources   ${CMAKE_CURRENT_SOURCE_DIR}/project/sources/)
set(prefixTests     ${CMAKE_CURRENT_SOURCE_DIR}/tests/)
set(prefixNcurses   ${CMAKE_CURRENT_SOURCE_DIR}/ncurses_library/sources/)
#set(prefixLib2 testLib2/sources/)
set(libDirectory    ${CMAKE_CURRENT_SOURCE_DIR}/libs)

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
        UI.cpp
        UIExceptions.cpp
        Map.cpp
        Bloc.cpp
        )

PREPEND(sourcesProject ${prefixSources} ${sourcesFiles})

# tests

set(sourcesTests UITests.cpp)

PREPEND(tests ${prefixTests} ${sourcesTests})

# ncurses
set(ncurses_URL "https://invisible-island.net/datafiles/release/ncurses.tar.gz")

add_custom_command(
        OUTPUT "${LibDirectory}"
        COMMAND file (DOWNLOAD "${ncurses_URL}" "${LibDirectory}")
        COMMAND tar xvzf ${libDirectory}/ncurses.tar.gz ${libDirectory}
        DEPENDS ${LibDirectory})

set(ncursesFiles
        Display.cpp
        Inputs.cpp
        )

PREPEND(sourcesNcurses ${prefixNcurses} ${ncursesFiles})

# lib 2

#set(lib2Files PartA.cpp PartB.cpp)

#PREPEND(sourcesLib2 ${prefixLib2} ${lib2Files})

# libraries

add_library(ncurses SHARED ${sourcesNcurses})

#add_library(lib2 SHARED ${sourcesLib2})

# exe

add_executable(nibbler project/sources/main.cpp ${sourcesProject})

# tests

add_executable(testAll ${sourcesProject} ${tests})

# add includes

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# set libs and executable properties

set_target_properties(ncurses PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${libDirectory}
        PREFIX ""
        SUFFIX ".so")

set_target_properties(nibbler PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# links

TARGET_LINK_LIBRARIES(nibbler ncurses)

#TARGET_LINK_LIBRARIES(nibbler lib2)