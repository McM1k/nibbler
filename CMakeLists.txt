cmake_minimum_required(VERSION 3.9)
project(abstract_vm_GH)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_STANDARD 11)

set(sourceCode )

set(HEADER_FILES )

add_executable(abstract_vm ${HEADER_FILES} sources/main.cpp ${sourceCode})