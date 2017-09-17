/**
 * @file /include/serial_control/main_window.hpp
 *
 * @brief Qt based gui for serial_control.
 *
 * @date November 2010
 **/
#ifndef serial_control_MAIN_WINDOW_H
#define serial_control_MAIN_WINDOW_H

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

namespace serial_control {

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
    void on_send_clicked();

    /******************************************
    ** Manual connections
    *******************************************/
    //void updateLoggingView(); // no idea why this can't connect automatically

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace serial_control

#endif // serial_control_MAIN_WINDOW_H
