cmake_minimum_required(VERSION 2.8.3)
project(robot_arm)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tf
  cv_bridge
)

find_package(OpenCV REQUIRED)

catkin_package()

set(CPP_FILES
    src/libs/robot_arm_class.cpp
    )

set(H_FILES
    include/robot_arm/robot_arm_class.h
    )

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(robot_arm src/robot_arm.cpp ${CPP_FILES})
target_link_libraries(robot_arm ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(robot_arm std_msgs ${catkin_EXPORTED_TARGETS})
