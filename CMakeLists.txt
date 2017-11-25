cmake_minimum_required(VERSION 3.0)
project(WittyHelloWorld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME ${PROJECT_NAME} CACHE STRING "Name of the executable")

find_library(WITTY NAMES wt)
find_library(WITTY_HTTP NAMES wthttp)

find_package(Boost QUIET
        COMPONENTS system thread filesystem program_options)

include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE PROJECT_SOURCES
        include/*.hpp
        helloworld/*.cpp)

set(SOURCE_FILES main.cpp ${PROJECT_SOURCES})
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${WITTY} ${WITTY_HTTP})

if (Boost_FOUND)
    message("Boost version: ${Boost_LIB_VERSION}")
    message("More information: https://cmake.org/cmake/help/v3.0/module/FindBoost.html")
    include_directories("${Boost_INCLUDE_DIRS}")
    link_directories(${Boost_LIBRARY_DIRS})
    target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
endif()

