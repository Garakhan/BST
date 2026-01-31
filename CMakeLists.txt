cmake_minimum_required(VERSION 3.10)
project(BST)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set (EXEC_SOURCE $ENV{EXEC_SOURCE})
set (EXEC_NAME $ENV{EXEC_NAME})
set (INCLUDE_DIR $ENV{INCLUDE_DIR})

add_executable(${EXEC_NAME} ${EXEC_SOURCE})
target_include_directories(${EXEC_NAME} PRIVATE ${INCLUDE_DIR})