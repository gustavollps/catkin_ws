/**
 * @file /include/serial_control/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef serial_control_QNODE_HPP_
#define serial_control_QNODE_HPP_

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

namespace serial_control {

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
  bool clicked;
  float kp;
  float ki;
  float kd;
  float setpoint;
  float min;
  float max;

  typedef union{
    float floatData;
    unsigned char byteData[4];
  }binaryFloat;

  /*********************
  ** Logging
  **********************/
  enum LogLevel {
    Debug,
    Info,
    Warn,
    Error,
    Fatal
  };

  QStringListModel* loggingModel() { return &logging_model; }
  //void log( const LogLevel &level, const std::string &msg);

Q_SIGNALS:
  void loggingUpdated();
  void rosShutdown();

private:
  int init_argc;
  char** init_argv;
  ros::Publisher serial_publisher;
  ros::ServiceClient pid_service;
  QStringListModel logging_model;
};

}  // namespace serial_control

#endif /* serial_control_QNODE_HPP_ */
