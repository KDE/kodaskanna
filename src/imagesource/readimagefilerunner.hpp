/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_READIMAGEFILERUNNER_HPP
#define KODASKANNA_IMAGESOURCE_READIMAGEFILERUNNER_HPP

// Qt
#include <QObject>
#include <QRunnable>

namespace Kodaskanna
{

namespace ImageSource
{

class ImageReadResult;

class ReadImageFileRunner : public QObject, public QRunnable
{
    Q_OBJECT

public:
    /// @param localFileName empty string refers to stdin
    explicit ReadImageFileRunner(const QString &localFileName);

public: // QRunnable API
    void run() override;

Q_SIGNALS:
    void readFinished(const Kodaskanna::ImageSource::ImageReadResult &imageReadResult);

private:
    const QString m_localFileName;
};

}
}

#endif
