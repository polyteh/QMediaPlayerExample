//
// Created by Oleksiy Grechnyev on 5/30/19.
//

#pragma once

#include <QtMultimedia>

class VSurface : public QAbstractVideoSurface {
Q_OBJECT

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
            QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const;

    bool present(const QVideoFrame &frame);

signals:

    /// Emit next frame in RGB24
    void nextFrame(void *buf, int w, int h);

};


