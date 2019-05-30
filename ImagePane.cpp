//
// Created by Oleksiy Grechnyev on 5/30/19.
//

#include <iostream>

#include "ImagePane.h"

void ImagePane::nextFrame(void *buf, int w, int h) {
    using namespace std;
//    cout << "Received Frame :" << w << " x " << h << endl;
    p.convertFromImage(QImage((uchar *)buf, w, h, w*3 , QImage::Format_RGB888));
    //if (width() != w || height() != h)
    // setFixedSize(w, h);
   // setPixmap(p);
    update();
}

ImagePane::ImagePane(QWidget *parent) :
        QLabel(parent) {

}

void ImagePane::paintEvent(QPaintEvent *event){
    QPainter painter(this);

      if (p.isNull()!=true) {
        QSize widgetSize = size();
        QPixmap scaledPixmap = p.scaled(widgetSize, Qt::KeepAspectRatio);
        QPoint center((widgetSize.width() - scaledPixmap.width())/2,
                      (widgetSize.height() - scaledPixmap.height())/2);
        painter.drawPixmap(center, scaledPixmap);
        //std::cout<<"current width"<<(int)scaledPixmap.width()<<std::endl;

      }

      QLabel::paintEvent(event);

}
