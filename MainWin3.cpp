//
// Created by Oleksiy Grechnyev on 5/30/19.
//

#include "MainWin3.h"

MainWin3::MainWin3(QMainWindow *parent) :
        QMainWindow(parent) {

    // Configure widgets
    imagePane = new ImagePane(this);

    pbPause = new QPushButton("Pause",this);
    pbPlay = new QPushButton("Play",this);
    pbPlayForward=new QPushButton("PlayForward",this);
    pbVLayout=new QVBoxLayout;
    pbVLayout->addWidget(pbPause);
    pbVLayout->addWidget(pbPlay);
    pbVLayout->addWidget(pbPlayForward);

    mainWindowLayout=new QHBoxLayout;
    mainWindowLayout->addWidget(imagePane);
    mainWindowLayout->addLayout(pbVLayout);



    QWidget *window = new QWidget();
    window->setLayout(mainWindowLayout);
    setCentralWidget(window);
    imagePane->setStyleSheet("border: 1px solid black");





    // Start the media player
    QSize imPaneSize (200,300);
    imagePane->setMinimumSize(imPaneSize);


    //imagePane->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    player.setMedia(QUrl::fromLocalFile(QFileInfo("./data/tvoya.mp4").absoluteFilePath()));
    player.setVideoOutput(&vSurface);
    player.setMuted(true);
    connect(&vSurface, &VSurface::nextFrame, imagePane, &ImagePane::nextFrame);
    connect(pbPause, &QPushButton::clicked, this, &MainWin3::on_pbPause_clicked);
    connect(pbPlay, &QPushButton::clicked, this, &MainWin3::on_pbPlay_clicked);
    connect(pbPlayForward, &QPushButton::clicked, this, &MainWin3::on_pbPlayForward_clicked);
    player.play();

}

void MainWin3::on_pbPause_clicked()
{
    player.pause();
}

void MainWin3::on_pbPlay_clicked()
{
    player.setPlaybackRate(1.0);
    player.play();
}

void MainWin3::on_pbPlayForward_clicked()
{

    player.setPlaybackRate(2.0);
    player.play();
}
