#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vlc/vlc.h>
#include <Qstring>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->widget->setStyleSheet("QFrame{background-color : red }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if((urlName = ui->lineEdit->text())!= NULL){
        const char * const vlc_argv[] = {
        "--network-caching=200"
//        "-I", "dummy",    //Don't use any interface

//        "--ignore-config" //Don't use VLC's config
        };
        static const int vlc_argv_nargs =
            sizeof (vlc_argv) / sizeof (vlc_argv[0]);
        inst = libvlc_new (vlc_argv_nargs, vlc_argv);                            //Load the VLC engine
//        inst = libvlc_new (0, NULL);
        m = libvlc_media_new_location(inst, urlName.toLatin1());//rtsp url 地址
        mp = libvlc_media_player_new_from_media (m);            //Create a media player playing environement
        libvlc_media_release (m);                               //No need to keep the media now

        //int windid = ui->widget->winId();

        libvlc_media_player_set_hwnd(mp, (void*)ui->widget->winId());
        //libvlc_media_player_set_xwindow(mp, windid);
        qDebug()<<"OK";

        libvlc_media_player_play (mp);                          //play the media_player
        qDebug()<<"player_play run";
    }
    else{
        QMessageBox::warning(this,tr("error"),tr("cannot open a blank URL!"),QMessageBox::Ok,QMessageBox::Ok);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    libvlc_media_player_stop (mp);      //Stop playing
    libvlc_media_player_release (mp);   //Free the media_player
    libvlc_release (inst);
}
