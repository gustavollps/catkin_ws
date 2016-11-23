#include "../include/a_star_test/LibAstar.h"
#include "std_msgs/String.h"
#include "tcc_msgs/location_goal.h"

Point start(0,0),goal(99,99);
LibAstar astar_router(goal,start);

void goalCallback(tcc_msgs::location_goal msg){
  start.x_ = msg.start.x;
  start.y_ = msg.start.y;

  goal.x_ = msg.goal.x;
  goal.y_ = msg.goal.y;
}

int main(int argc, char *argv[]){

	ros::init(argc, argv, "A_STAR");
  ros::NodeHandle nh;
  ros::Rate loopRate(10);

  std_msgs::String str_msg;
  std::string str;

  ros::Publisher pub_route = nh.advertise<std_msgs::String>("/Route",10);
  ros::Subscriber sub_positions = nh.subscribe<tcc_msgs::location_goal>("/Position_Goal",10,goalCallback);
  while(ros::ok()){
    astar_router.goal_ = goal;
    astar_router.start_ = start;
    str = astar_router.pathFinder();
    if(!str.empty()){
      str_msg.data = str;
      pub_route.publish(str_msg);
    }
    ros::spinOnce();
    loopRate.sleep();
  }
	return 0;
}
