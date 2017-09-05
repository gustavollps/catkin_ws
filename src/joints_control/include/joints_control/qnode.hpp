/**
 * @file /include/joints_control/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef joints_control_QNODE_HPP_
#define joints_control_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#endif

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace joints_control {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();

  float art_1;
  float art_2;
  float art_3;
  float art_4;
  float art_5;
  float art_6;

Q_SIGNALS:	
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
  ros::Publisher joints_pub_;

};

}  // namespace joints_control

#endif /* joints_control_QNODE_HPP_ */
