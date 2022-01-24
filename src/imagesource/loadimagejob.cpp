/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "loadimagejob.hpp"

// oww
#include "readimagefilerunner.hpp"
#include "imagereadresult.hpp"
// KF
#include <KIO/FileCopyJob>
#include <KLocalizedString>
// Qt
#include <QTemporaryFile>
#include <QThreadPool>

namespace Kodaskanna
{

namespace ImageSource
{

LoadImageJob::LoadImageJob(const QUrl &fileUrl)
    : m_fileUrl(fileUrl)
{
}

LoadImageJob::~LoadImageJob()
{
    if (m_fileCopyJob) {
        m_fileCopyJob->kill();
    }
}

void LoadImageJob::start()
{
    if (m_fileUrl.isLocalFile()) {
        startFileReading(m_fileUrl.toLocalFile());
        return;
    }

    // create a unique temporary file we use for the download
    m_tmpFile = new QTemporaryFile(this);
    m_tmpFile->open();

    m_fileCopyJob = KIO::file_copy(m_fileUrl, QUrl::fromLocalFile(m_tmpFile->fileName()), -1, KIO::Overwrite);

    connect(m_fileCopyJob, &KJob::finished, this, &LoadImageJob::handleFileCopyFinished);
    m_fileCopyJob->start();
}

QImage LoadImageJob::image() const
{
    return m_image;
}

void LoadImageJob::startFileReading(const QString &localFileName)
{
    auto *loadImageRunner = new ReadImageFileRunner(localFileName);
    qRegisterMetaType<Kodaskanna::ImageSource::ImageReadResult>();
    connect(loadImageRunner, &ReadImageFileRunner::readFinished, this, &LoadImageJob::handleReadFinished);

    QThreadPool::globalInstance()->start(loadImageRunner);
}

void LoadImageJob::handleFileCopyFinished(KJob *job)
{
    m_fileCopyJob = nullptr;

    if (job->error() != 0) {
        setError(job->error());
        setErrorText(job->errorText());
        emitResult();
        return;
    }

    startFileReading(m_tmpFile->fileName());
}

void LoadImageJob::handleReadFinished(const ImageReadResult &imageReadResult)
{
    if (imageReadResult.isSuccess()) {
        m_image = imageReadResult.image();
    } else {
        setError(KJob::UserDefinedError);
        setErrorText(i18n("Could not load image from file %1.", m_fileUrl.toDisplayString()));
    }

    emitResult();
}

}
}
