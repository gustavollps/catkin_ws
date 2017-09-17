/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/joints_control/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace joints_control {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
	** Logging
	**********************/
  //ui.view_logging->setModel(qnode.loggingModel());
  //QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
		}
	}
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
//void MainWindow::updateLoggingView() {
//        ui.view_logging->scrollToBottom();
//}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "joints_control");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "joints_control");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

}  // namespace joints_control

void joints_control::MainWindow::on_horizontalSlider_1_valueChanged(int position)
{
  qnode.art_1 = position;
}

void joints_control::MainWindow::on_horizontalSlider_2_valueChanged(int position)
{
  qnode.art_2 =position;
}

void joints_control::MainWindow::on_horizontalSlider_3_valueChanged(int position)
{
  qnode.art_3 =position;
}

void joints_control::MainWindow::on_horizontalSlider_4_valueChanged(int position)
{
  qnode.art_4 =position;
}

void joints_control::MainWindow::on_horizontalSlider_5_valueChanged(int position)
{
  qnode.art_5 =position;
}

void joints_control::MainWindow::on_horizontalSlider_6_valueChanged(int position)
{
  qnode.art_6 =position;
}


void joints_control::MainWindow::on_pose1_clicked()
{
   ui.horizontalSlider_1->setValue(0);
   ui.horizontalSlider_2->setValue(500);
   ui.horizontalSlider_3->setValue(500);
   ui.horizontalSlider_4->setValue(0);
   ui.horizontalSlider_5->setValue(500);
   ui.horizontalSlider_6->setValue(0);
}

void joints_control::MainWindow::on_pose2_clicked()
{
  ui.horizontalSlider_1->setValue(0);
  ui.horizontalSlider_2->setValue(592);
  ui.horizontalSlider_3->setValue(984);
  ui.horizontalSlider_4->setValue(0);
  ui.horizontalSlider_5->setValue(308);
  ui.horizontalSlider_6->setValue(0);
}

void joints_control::MainWindow::on_pose3_clicked()
{
  ui.horizontalSlider_1->setValue(0);
  ui.horizontalSlider_2->setValue(200);
  ui.horizontalSlider_3->setValue(1000);
  ui.horizontalSlider_4->setValue(0);
  ui.horizontalSlider_5->setValue(308);
  ui.horizontalSlider_6->setValue(0);
}

void joints_control::MainWindow::on_pose4_clicked()
{
  ui.horizontalSlider_1->setValue(500);
  ui.horizontalSlider_2->setValue(840);
  ui.horizontalSlider_3->setValue(788);
  ui.horizontalSlider_4->setValue(748);
  ui.horizontalSlider_5->setValue(132);
  ui.horizontalSlider_6->setValue(0);
}

void joints_control::MainWindow::on_pose5_clicked()
{
  ui.horizontalSlider_1->setValue(0);
  ui.horizontalSlider_2->setValue(336);
  ui.horizontalSlider_3->setValue(1000);
  ui.horizontalSlider_4->setValue(0);
  ui.horizontalSlider_5->setValue(256);
  ui.horizontalSlider_6->setValue(0);
}

void joints_control::MainWindow::on_pose6_clicked()
{

}
