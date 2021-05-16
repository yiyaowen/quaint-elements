cmake_minimum_required(VERSION 3.5)

project(QuaintElements)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

file(GLOB ${PROJECT_NAME}SourceFiles "*.cpp")
file(GLOB ${PROJECT_NAME}HeaderFiles "*.h")

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}SourceFiles}
    ${${PROJECT_NAME}HeaderFiles}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
