cmake_minimum_required(VERSION 3.25)
project(c_xml C)

set(CMAKE_C_STANDARD 11)

add_executable(c_xml main.c)

find_package(LibXml2 REQUIRED)
target_link_libraries(c_xml PRIVATE LibXml2::LibXml2)