//
// Created by Oleksiy Grechnyev on 5/30/19.
//

#include <iostream>

#include "VSurface.h"

bool VSurface::present(const QVideoFrame &frame) {
    Q_UNUSED(frame);
    // Handle the frame and do your processing
    using namespace std;
    QVideoFrame q = frame;
    int h = q.height(), w = frame.width();
//    cout << "Frame :" << w << " x " << h << endl;
    q.map(QAbstractVideoBuffer::ReadOnly);
//    cout << q.isMapped() << endl;

    emit nextFrame(q.bits(), w, h);

    return true;
}

QList<QVideoFrame::PixelFormat> VSurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const {
    Q_UNUSED(handleType);

    // Return the formats you will support
    return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB24;
}
