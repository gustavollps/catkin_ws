/**
 * @file /include/joints_control/main_window.hpp
 *
 * @brief Qt based gui for joints_control.
 *
 * @date November 2010
 **/
#ifndef joints_control_MAIN_WINDOW_H
#define joints_control_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>

#ifndef Q_MOC_RUN

#include "ui_main_window.h"
#include "qnode.hpp"

#endif

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace joints_control {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
  *******************************************/

	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);
  void on_horizontalSlider_1_valueChanged(int position);
  void on_horizontalSlider_2_valueChanged(int position);
  void on_horizontalSlider_3_valueChanged(int position);
  void on_horizontalSlider_4_valueChanged(int position);
  void on_horizontalSlider_5_valueChanged(int position);
  void on_horizontalSlider_6_valueChanged(int position);
  void on_pose1_clicked();
  void on_pose2_clicked();
  void on_pose3_clicked();
  void on_pose4_clicked();
  void on_pose5_clicked();
  void on_pose6_clicked();


    /******************************************
    ** Manual connections
    *******************************************/
//    void updateLoggingView(); // no idea why this can't connect automatically


private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace joints_control

#endif // joints_control_MAIN_WINDOW_H
