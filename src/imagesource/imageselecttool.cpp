/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "imageselecttool.hpp"

// own
#include "tool.hpp"
// KF
#include <KLocalizedString>
// Qt
#include <QApplication>
#include <QClipboard>
#include <QFileDialog>
#include <QImage>
#include <QMimeData>
#include <QUrl>

namespace Kodaskanna
{
namespace ImageSource
{

ImageSelectTool::ImageSelectTool(Tool *tool)
    : m_tool(tool)
{
}

bool ImageSelectTool::canHandleMimeData(const QMimeData *mimeData) const
{
    if (mimeData->hasImage()) {
        return true;
    }

    if (mimeData->hasUrls()) {
        const QList<QUrl> urls = mimeData->urls();
        if ((urls.size() == 1) && urls.first().isLocalFile()) {
            return true;
        }
    }

    return false;
}

bool ImageSelectTool::handleDroppedMimeData(const QMimeData *mimeData)
{
    if (mimeData->hasImage()) {
        const QImage image = qvariant_cast<QImage>(mimeData->imageData());
        m_tool->setImage(image);
        return true;
    }

    if (mimeData->hasUrls()) {
        const QList<QUrl> urls = mimeData->urls();
        if ((urls.size() == 1) && urls.first().isLocalFile()) {
            m_tool->setOrigin(urls.first().toLocalFile());
            return true;
        }
    }

    return false;
}

void ImageSelectTool::openFile()
{
    const QString localFileName = QFileDialog::getOpenFileName(nullptr, i18nc("@title:window", "Open Image"));
    if (localFileName.isEmpty()) {
        return;
    }

    m_tool->setOrigin(localFileName);
}

void ImageSelectTool::pasteFromClipboard()
{
    handleDroppedMimeData(QApplication::clipboard()->mimeData());
}

}
}
