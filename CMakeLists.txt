cmake_minimum_required(VERSION 3.16)
project(cmake_clion_conan_template)

# Author : Akide Liu (https://github.com/AkideLiu)
# This template integrated Cmake Clion Conan for University of Adelaide C++ direction course educational purpose only

# -------------------------------------------------------
# Basic Step
# C++ standard and flags

set(CMAKE_CXX_STANDARD 11)

#This should be my default compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

#SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow -Woverloaded-virtual -Winvalid-pch -Wcast-align -Wformat=2 -Wformat-nonliteral -Wmissing-declarations -Wmissing-format-attribute -Wmissing-include-dirs -Wredundant-decls -Wswitch-default")

# -------------------------------------------------------

# enable conan support by conan cmake project
# Further Instructions and Documents refer : https://github.com/conan-io/cmake-conan

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
            TLS_VERIFY ON)
endif()

#including dependencies headers
include(${CMAKE_BINARY_DIR}/conan.cmake)

# configure the frameworks support
# External framework or libs could be found on https://conan.io/center/

conan_cmake_run(REQUIRES

        dbg-macro/0.4.0
        gtest/1.10.0
        fmt/7.1.3

        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

conan_basic_setup()

# -------------------------------------------------------
# customized setup

add_executable(cmake_clion_template main.cpp)

# important ! link libs to executable target
target_link_libraries(cmake_clion_template
        ${CONAN_LIBS}
        )

# -------------------------------------------------------
# subdirectory support
add_subdirectory(src/AVLTree)
