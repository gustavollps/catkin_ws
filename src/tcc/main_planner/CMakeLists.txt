cmake_minimum_required(VERSION 2.8.3)
project(main_planner)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tcc_msgs
  control_loop
)


catkin_package(
    INCLUDE_DIRS include
    LIBRARIES PID
    CATKIN_DEPENDS roscpp std_msgs tcc_msgs control_loop
    )


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PID_INCLUDE_DIRS}
)

add_executable(main_planner src/main_planner.cpp ${CPP_FILES})
add_dependencies(main_planner tcc_msgs PID ${catkin_EXPORTED_TARGETS})
target_link_libraries(main_planner ${catkin_LIBRARIES} ${PID_LIBRARIES})
