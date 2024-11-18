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
        if (urls.size() == 1) {
            return true;
        }
    }

    return false;
}

bool ImageSelectTool::handleMimeData(const QMimeData *mimeData)
{
    if (mimeData->hasImage()) {
        const QImage image = qvariant_cast<QImage>(mimeData->imageData());
        m_tool->setImage(image);
        return true;
    }

    if (mimeData->hasUrls()) {
        const QList<QUrl> urls = mimeData->urls();
        if (urls.size() == 1) {
            m_tool->setOrigin(urls.first());
            return true;
        }
    }

    return false;
}

void ImageSelectTool::openFile()
{
    const QUrl fileUrl = QFileDialog::getOpenFileUrl(nullptr, i18nc("@title:window", "Open Image"));
    if (fileUrl.isEmpty()) {
        return;
    }

    m_tool->setOrigin(fileUrl);
}

}
}
