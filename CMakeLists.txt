cmake_minimum_required(VERSION 2.8)
project( webcam )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( webcam webcam.cpp greenDetection.cpp)
target_link_libraries( webcam ${OpenCV_LIBS} )

