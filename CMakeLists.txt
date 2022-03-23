cmake_minimum_required(VERSION 3.17)
project(Socket)

set(CMAKE_CXX_STANDARD 14)

add_executable(Socket main.cpp Linux/inet_addr.cpp Linux/inet_aton.cpp)

if(WIN32)
    target_link_libraries(Socket wsock32 ws2_32)
endif()