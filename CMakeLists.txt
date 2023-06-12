cmake_minimum_required(VERSION 3.22)

project(TicTacToe VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/home/edc/Qt5.7.0/5.7/gcc_64/lib/cmake/")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_subdirectory(src/app)
add_subdirectory(src/domain)
add_subdirectory(src/impl)