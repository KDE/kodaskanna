/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "tool.hpp"

// own
#include "loadimagejob.hpp"
#include "imageselecttool.hpp"
#include "widget.hpp"
// core
#include <scanimagerunner.hpp>
#include <scanresult.hpp>
// Qt
#include <QImage>
#include <QThreadPool>

namespace Kodaskanna
{
namespace ImageSource
{

Tool::Tool(QObject *parent)
    : AbstractSourceTool(parent)
    , m_widget(new Widget)
{
}

Tool::~Tool() = default;

QWidget *Tool::widget()
{
    return m_widget;
}

void Tool::setOrigin(const QUrl &origin)
{
    if (origin.isEmpty()) {
        if (!m_imageSelectTool) {
            m_imageSelectTool = std::make_unique<ImageSelectTool>(this);
            m_widget->showImageSelect(m_imageSelectTool.get());
        }
        return;
    }

    m_widget->setEnabled(false);

    auto *loadImageJob = new LoadImageJob(origin);
    connect(loadImageJob, &LoadImageJob::result, this, &Tool::handleImageLoadResult);

    loadImageJob->start();
}

void Tool::setImage(const QImage &image)
{
    m_widget->setImage(image);

    auto *scanImageRunner = new ScanImageRunner(image);
    qRegisterMetaType<Kodaskanna::ScanResult>();
    connect(scanImageRunner, &ScanImageRunner::scanFinished, this, &Tool::handleScanFinished);

    QThreadPool::globalInstance()->start(scanImageRunner);
}

void Tool::handleImageLoadResult(KJob *job)
{
    m_widget->setEnabled(true);

    auto *loadImageJob = static_cast<LoadImageJob*>(job);
    if (loadImageJob->error() != 0) {
        m_widget->showError(loadImageJob->errorString());
        return;
    }

    setImage(loadImageJob->image());
}

void Tool::handleScanFinished(const ScanResult &scanResult)
{
    if (!scanResult.isSuccess()) {
        m_widget->showError(i18n("Could not scan code in the image."));
    } else {
        m_widget->showSuccess(i18n("Code in the image successfully scanned."));
    }

    Q_EMIT scanFinished(scanResult);
}

}
}

#include "moc_tool.cpp"
