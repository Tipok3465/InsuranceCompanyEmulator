cmake_minimum_required(VERSION 3.26)
project(InsuranceCompanyEmulatorTrue)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(InsuranceCompanyEmulatorTrue main.cpp
        src/header.h
        src/Front/App.cpp
        src/Front/App.h)
target_link_libraries(InsuranceCompanyEmulatorTrue
        Qt6::Widgets
)
