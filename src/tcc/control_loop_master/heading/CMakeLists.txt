cmake_minimum_required(VERSION 2.8.3)
project(heading)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)



catkin_package()

FIND_LIBRARY(WIRINGPI_LIBRARY wiringPi /home/odroid/wiringPi)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(heading src/heading.cpp)
add_dependencies(heading wiringPi ${catkin_EXPORTED_TARGETS})
target_link_libraries(heading ${catkin_LIBRARIES} ${WIRINGPI_LIBRARY})
