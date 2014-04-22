#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vlc/vlc.h>
#include <Qstring>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // libvlc_instance_t *inst = new libvlc_instance_t;
  //  libvlc_media_player_t *mp = new libvlc_media_player_t;
   // libvlc_media_player_t *m = new libvlc_media_player_t;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if((urlName = ui->lineEdit->text())!= NULL){
        inst = libvlc_new (0, NULL);        /* Load the VLC engine */
        m = libvlc_media_new_location(inst, urlName.toLatin1());//"rtsp://192.168.233.131/slamtv60.264");
            //m = libvlc_media_new_path (inst,"rtsp:/192.168.5.1:8554\/slamtv60.264" );  /* Create a new item  english must*/
        mp = libvlc_media_player_new_from_media (m);    /* Create a media player playing environement */
        libvlc_media_release (m);           /* No need to keep the media now */
            // 播放
        libvlc_media_player_play (mp);      /* play the media_player */
    }
    else{
        QMessageBox::warning(this,tr("error"),tr("cannot open a blank URL!"),QMessageBox::Ok,QMessageBox::Ok);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    libvlc_media_player_stop (mp);      /* Stop playing */
    libvlc_media_player_release (mp);   /* Free the media_player */
    libvlc_release (inst);
}
