/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/serial_control/qnode.hpp"
#include "../include/serial_control/main_window.hpp"
#include "serial_node/PIDparams.h"
#include "tcc_msgs/changePID.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace serial_control {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
  init_argc(argc),
  init_argv(argv)
{
  clicked = false;
  kp = 0.0;
  ki = 0.0;
  kd = 0.0;
  setpoint = 0.0;
  min = 0.0;
  max = 0.0;
}

QNode::~QNode() {
  if(ros::isStarted()) {
    ros::shutdown(); // explicitly needed since we use ros::start();
    ros::waitForShutdown();
  }
  wait();
}

bool QNode::init() {
  ros::init(init_argc,init_argv,"serial_control");
  if ( ! ros::master::check() ) {
    return false;
  }
  ros::start(); // explicitly needed since our nodehandle is going out of scope.
  ros::NodeHandle n;
  // Add your ros communications here.
  serial_publisher = n.advertise<serial_node::PIDparams>("SERIAL_IN", 100);
  start();
  return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
  std::map<std::string,std::string> remappings;
  remappings["__master"] = master_url;
  remappings["__hostname"] = host_url;
  ros::init(remappings,"serial_control");
  if ( ! ros::master::check() ) {
    return false;
  }
  ros::start(); // explicitly needed since our nodehandle is going out of scope.
  ros::NodeHandle n;
  serial_publisher = n.advertise<serial_node::PIDparams>("SERIAL_IN", 100);
  pid_service = n.serviceClient<tcc_msgs::changePID>("/ChangePID");
  start();
  return true;
}

void QNode::run() {
  ros::Rate loop_rate(10);
  ros::NodeHandle n;
  //int count = 0;
  while ( ros::ok() ) {

    serial_node::PIDparams msg;

    if(clicked){
      clicked = false;
      /*
       * msg.kp = kp;
         msg.ki = ki;
         msg.kd = kd;
         msg.setpoint = setpoint;
         msg.min = min;
         msg.max = max;
       * serial_publisher.publish(msg);
       */
      n.setParam("/Main_Planner/Kp",kp);
      n.setParam("/Main_Planner/Ki",ki);
      n.setParam("/Main_Planner/Kd",kd);
      n.setParam("/Main_Planner/Angle_Setpoint",setpoint);
      n.setParam("/Main_Planner/DeadzoneSize",max);
      tcc_msgs::changePID srv;
      pid_service.call(srv);
    }

    //log(Info,std::string("I sent: ")+msg.data);
    ros::spinOnce();
    loop_rate.sleep();
  }
  std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
  Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


/*void QNode::log( const LogLevel &level, const std::string &msg) {
  logging_model.insertRows(logging_model.rowCount(),1);
  std::stringstream logging_model_msg;
  switch ( level ) {
    case(Debug) : {
        ROS_DEBUG_STREAM(msg);
        logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
        break;
    }
    case(Info) : {
        ROS_INFO_STREAM(msg);
        logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
        break;
    }
    case(Warn) : {
        ROS_WARN_STREAM(msg);
        logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
        break;
    }
    case(Error) : {
        ROS_ERROR_STREAM(msg);
        logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
        break;
    }
    case(Fatal) : {
        ROS_FATAL_STREAM(msg);
        logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
        break;
    }
  }
  QVariant new_row(QString(logging_model_msg.str().c_str()));
  logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
  Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}*/

}  // namespace serial_control
