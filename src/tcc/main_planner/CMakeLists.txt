cmake_minimum_required(VERSION 2.8.3)
project(main_planner)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
  tcc_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES main_planner
#  CATKIN_DEPENDS roscpp sensor_msgs std_msgs tcc_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
