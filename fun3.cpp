#include <QtWidgets>

#include "./MainWin3.h"

/// By Oleksiy Grechnyev
/// Here I try to play a video by converting QVideoFrame to QPixmap

int main(int argc, char **argv){
    QApplication app(argc, argv);
    qDebug() << "QT_VERSION (COMPILE TIME) = " << QT_VERSION_STR;
    qDebug() << "QT_VERSION (RUN TIME) = " << qVersion();

    MainWin3 w;
    w.show();

    return app.exec();
}
