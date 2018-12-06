cmake_minimum_required(VERSION 3.9)
project(abstract_vm)

set(CMAKE_CXX_STANDARD 11)

set(sourceCode sources/main.cpp)

add_executable(nibbler ${sourceCode})

#add_executable(testsAll ${HEADER_FILES} ${sourceCode} ${testLexerCode} ${testParserCode} ${testMainCode})