/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "readimagefilerunner.hpp"

// own
#include "imagereadresult.hpp"
#include "imagereadresult_p.hpp"
// KF
#include <KLocalizedString>
// Qt
#include <QFile>
#include <QImageReader>
// Std
#include <unistd.h>

namespace Kodaskanna
{

namespace ImageSource
{

ReadImageFileRunner::ReadImageFileRunner(const QString &localFileName)
    : m_localFileName(localFileName)
{
}

void ReadImageFileRunner::run()
{
    QFile input;
    if (m_localFileName.isEmpty()) {
        input.open(stdin, QIODevice::ReadOnly | QIODevice::Unbuffered);
    } else {
        input.setFileName(m_localFileName);
        input.open(QIODevice::ReadOnly);
    }
    QImageReader reader(&input);
    reader.setAutoTransform(true);
    const QImage loadedImage = reader.read();

    auto *resultData = new ImageReadResultPrivate;
    ImageReadResult imageReadResult(resultData);

    resultData->isSuccess = !loadedImage.isNull();
    if (resultData->isSuccess) {
        resultData->image = loadedImage;
    }

    Q_EMIT readFinished(imageReadResult);
}

}
}

#include "moc_readimagefilerunner.cpp"
