cmake_minimum_required(VERSION 3.20)

project($ENV{projectName})
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC src/*)
file(GLOB INCLUDES RELATIVE ${INCLUDE_DIR} ${INCLUDE_DIR}/*)

add_executable(${PROJECT_NAME} $ENV{fileName} ${SRC})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)


foreach(DIRS ${INCLUDES})
    if (IS_DIRECTORY ${INCLUDE_DIR}/${DIRS})
        target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR}/${DIRS})
    endif()
endforeach()