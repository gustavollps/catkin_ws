cmake_minimum_required(VERSION 2.8.3)

project(trabalho_final)

find_package(catkin REQUIRED COMPONENTS
  roscpp geometry_msgs sensor_msgs std_msgs message_generation
)

add_service_files(
  FILES
  ChangeGoal.srv
)

generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
    INCLUDE_DIRS include
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

set(H_FILES
    include/Node.h
    include/EmissorNode.h
    )


set(CPP_FILES
    src/libs/Node.cpp
    src/libs/EmissorNode.cpp
    )

add_executable(controlador src/controlador.cpp ${CPP_FILES})
add_dependencies(controlador trabalho_final_generate_messages_cpp ${catkin_EXPORTED_TARGETS})
target_link_libraries(controlador ${catkin_LIBRARIES})
