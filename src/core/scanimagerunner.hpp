/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_SCANIMAGERUNNER_HPP
#define KODASKANNA_SCANIMAGERUNNER_HPP

// Qt
#include <QImage>
#include <QObject>
#include <QRunnable>

namespace Kodaskanna
{

class ScanResult;

class ScanImageRunner : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit ScanImageRunner(const QImage &image);

public: // QRunnable API
    void run() override;

Q_SIGNALS:
    void scanFinished(const Kodaskanna::ScanResult &scanResult);

private:
    QImage m_image;
};

}

#endif
