cmake_minimum_required(VERSION 2.8.3)
project(pwm)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tcc_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(pwm src/pwm_master.cpp)
target_link_libraries(pwm ${catkin_LIBRARIES})
add_dependencies(pwm tcc_msgs)
