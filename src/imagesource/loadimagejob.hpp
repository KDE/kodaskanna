/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_LOADIMAGEJOB_HPP
#define KODASKANNA_IMAGESOURCE_LOADIMAGEJOB_HPP

// KF
#include <KJob>
// Qt
#include <QImage>
#include <QObject>
#include <QUrl>

namespace KIO { class FileCopyJob; }
class QTemporaryFile;

namespace Kodaskanna
{

namespace ImageSource
{

class ImageReadResult;

class LoadImageJob : public KJob
{
    Q_OBJECT

public:
    explicit LoadImageJob(const QUrl &fileUrl);
    ~LoadImageJob() override;

public: // KJob API
    void start() override;

public:
    QImage image() const;

Q_SIGNALS:
    void loadFinished(const Kodaskanna::ImageSource::ImageReadResult &imageReadResult);

private Q_SLOTS:
    void handleReadFinished(const ImageReadResult &imageReadResult);
    void handleFileCopyFinished(KJob *job);

private:
    /// @param localFileName empty string refers to stdin
    void startFileReading(const QString &localFileName);

private:
    const QUrl m_fileUrl;

    QImage m_image;

    KIO::FileCopyJob* m_fileCopyJob = nullptr;
    QTemporaryFile *m_tmpFile = nullptr;
};

}
}

#endif
