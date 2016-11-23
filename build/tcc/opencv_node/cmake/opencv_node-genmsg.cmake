# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "opencv_node: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(opencv_node_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/opencv_node/srv/SetParams.srv" NAME_WE)
add_custom_target(_opencv_node_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "opencv_node" "/home/tony/catkin_ws/src/tcc/opencv_node/srv/SetParams.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(opencv_node
  "/home/tony/catkin_ws/src/tcc/opencv_node/srv/SetParams.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_node
)

### Generating Module File
_generate_module_cpp(opencv_node
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_node
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(opencv_node_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(opencv_node_generate_messages opencv_node_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/opencv_node/srv/SetParams.srv" NAME_WE)
add_dependencies(opencv_node_generate_messages_cpp _opencv_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_node_gencpp)
add_dependencies(opencv_node_gencpp opencv_node_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_node_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(opencv_node
  "/home/tony/catkin_ws/src/tcc/opencv_node/srv/SetParams.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_node
)

### Generating Module File
_generate_module_lisp(opencv_node
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_node
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(opencv_node_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(opencv_node_generate_messages opencv_node_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/opencv_node/srv/SetParams.srv" NAME_WE)
add_dependencies(opencv_node_generate_messages_lisp _opencv_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_node_genlisp)
add_dependencies(opencv_node_genlisp opencv_node_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_node_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(opencv_node
  "/home/tony/catkin_ws/src/tcc/opencv_node/srv/SetParams.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node
)

### Generating Module File
_generate_module_py(opencv_node
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(opencv_node_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(opencv_node_generate_messages opencv_node_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/opencv_node/srv/SetParams.srv" NAME_WE)
add_dependencies(opencv_node_generate_messages_py _opencv_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_node_genpy)
add_dependencies(opencv_node_genpy opencv_node_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_node_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_node
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(opencv_node_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_node
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(opencv_node_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(opencv_node_generate_messages_py std_msgs_generate_messages_py)
