cmake_minimum_required(VERSION 3.10)

project(encrypt_dat)

find_package(fmt CONFIG REQUIRED)

add_executable(encrypt_dat encrypt_dat.cpp)

target_link_libraries(encrypt_dat PRIVATE fmt::fmt)