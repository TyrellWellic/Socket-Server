cmake_minimum_required(VERSION 3.1)
project(Socket-Server)

find_library(PTHREAD_LIBRARY pthread)
file(GLOB CPPS "*.cpp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

add_executable(${PROJECT_NAME} ${CPPS})

target_link_libraries(${PROJECT_NAME} ${PTHREAD_LIBRARY})
