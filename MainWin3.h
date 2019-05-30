//
// Created by Oleksiy Grechnyev on 5/30/19.
//

#pragma once

#include <iostream>

#include <QtWidgets>
#include <QtMultimedia>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include <QSize>

#include "VSurface.h"
#include "ImagePane.h"


class MainWin3 : public QMainWindow {
Q_OBJECT

    Q_DISABLE_COPY(MainWin3)

public:
    explicit MainWin3(QMainWindow *parent = nullptr);

private:
    QMediaPlayer player;

    VSurface vSurface;
    ImagePane *imagePane;
    QPushButton *pbPause, *pbPlay, *pbPlayForward;
    QVBoxLayout *pbVLayout;
    QHBoxLayout *mainWindowLayout;

private:
    void on_pbPause_clicked();
    void on_pbPlay_clicked();
    void on_pbPlayForward_clicked();
};


