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
#include <std_msgs/Float32MultiArray.h>
#include <sstream>
#include "../include/joints_control/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace joints_control {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"joints_control");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
  art_1 = 0;
  art_2 = 500;
  art_3 = 500;
  art_4 = 0;
  art_5 = 500;
  art_6 = 0;

  joints_pub_ = n.advertise<std_msgs::Float32MultiArray>("joints_states", 10);
	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"joints_control");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
  art_1 = 0;
  art_2 = 500;
  art_3 = 500;
  art_4 = 0;
  art_5 = 500;
  art_6 = 0;

	// Add your ros communications here.
  joints_pub_ = n.advertise<std_msgs::Float32MultiArray>("joints_states", 10);
	start();
	return true;
}

void QNode::run() {
  ros::Rate loop_rate(50);

	while ( ros::ok() ) {
    std_msgs::Float32MultiArray msg;

    msg.data.clear();

    msg.data.push_back(art_1);
    msg.data.push_back(art_2);
    msg.data.push_back(art_3);
    msg.data.push_back(art_4);
    msg.data.push_back(art_5);
    msg.data.push_back(art_6);

    joints_pub_.publish(msg);

		ros::spinOnce();
		loop_rate.sleep();		
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace joints_control
