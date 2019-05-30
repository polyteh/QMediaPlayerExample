cmake_minimum_required(VERSION 3.1)
project(fun3)
set(CXX_STANDARD 14)

file(COPY data DESTINATION .)

#Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS Widgets Multimedia REQUIRED)

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})




add_executable(${PROJECT_NAME} fun3.cpp MainWin3.cpp MainWin3.h VSurface.cpp VSurface.h ImagePane.cpp ImagePane.h)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Multimedia)






