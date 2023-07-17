/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "imageselectwidget.hpp"

// own
#include "imageselecttool.hpp"
// Qt
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>

namespace Kodaskanna
{
namespace ImageSource
{

ImageSelectWidget::ImageSelectWidget(ImageSelectTool *imageSelectTool, QWidget *parent)
    : QWidget(parent)
    , m_imageSelectTool(imageSelectTool)
{
    m_ui.setupUi(this);
    setAcceptDrops(true);

    connect(m_ui.openFileButton, &QPushButton::clicked, this, &ImageSelectWidget::openFile);
    connect(m_ui.pasteFromClipboardButton, &QPushButton::clicked, this, &ImageSelectWidget::pasteFromClipboard);
}

ImageSelectWidget::~ImageSelectWidget() = default;

void ImageSelectWidget::dragEnterEvent(QDragEnterEvent *dragEnterEvent)
{
    if (m_imageSelectTool->canHandleMimeData(dragEnterEvent->mimeData())) {
        dragEnterEvent->accept();
    } else {
        dragEnterEvent->ignore();
    }
}

void ImageSelectWidget::dragMoveEvent(QDragMoveEvent *dragMoveEvent)
{
    if (m_imageSelectTool->canHandleMimeData(dragMoveEvent->mimeData())) {
        dragMoveEvent->accept();
    } else {
        dragMoveEvent->ignore();
    }
}

void ImageSelectWidget::dragLeaveEvent(QDragLeaveEvent *dragLeaveEvent)
{
    dragLeaveEvent->accept();
}

void ImageSelectWidget::dropEvent(QDropEvent *dropEvent)
{
    if (m_imageSelectTool->handleDroppedMimeData(dropEvent->mimeData())) {
        dropEvent->accept();
    } else {
        dropEvent->ignore();
    }
}

void ImageSelectWidget::openFile()
{
    m_imageSelectTool->openFile();
}

void ImageSelectWidget::pasteFromClipboard()
{
    m_imageSelectTool->pasteFromClipboard();
}

}
}

#include "moc_imageselectwidget.cpp"
