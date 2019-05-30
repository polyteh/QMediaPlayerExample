//
// Created by Oleksiy Grechnyev on 5/30/19.
//

#pragma once

#include <QtWidgets>

class ImagePane : public QLabel {

Q_OBJECT

    Q_DISABLE_COPY(ImagePane)
public:
    explicit ImagePane(QWidget *parent = nullptr);

public slots:
    void nextFrame(void *buf, int w, int h);

private:
    void paintEvent(QPaintEvent *event);

private:
    QPixmap p;
};


