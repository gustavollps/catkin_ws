cmake_minimum_required(VERSION 2.8.3)
project(interrupts)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tcc_msgs
)



catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES interrupts
#  CATKIN_DEPENDS pwm roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(interrupts src/interrupts.cpp)
add_dependencies(interrupts tcc_msgs ${catkin_EXPORTED_TARGETS})
target_link_libraries(interrupts ${catkin_LIBRARIES})
