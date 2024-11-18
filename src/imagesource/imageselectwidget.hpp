/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_IMAGESELECTWIDGET_HPP
#define KODASKANNA_IMAGESOURCE_IMAGESELECTWIDGET_HPP

// own
#include "ui_imageselectwidget.h"
// Qt
#include <QWidget>

namespace Kodaskanna
{
namespace ImageSource
{
class ImageSelectTool;

class ImageSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageSelectWidget(ImageSelectTool *imageSelectTool, QWidget *parent = nullptr);

    ~ImageSelectWidget() override;

protected: // QWidget API
    void dragEnterEvent(QDragEnterEvent *dragEnterEvent) override;
    void dragMoveEvent(QDragMoveEvent *dragMoveEvent) override;
    void dragLeaveEvent(QDragLeaveEvent *dragLeaveEvent) override;
    void dropEvent(QDropEvent *dropEvent) override;

private:
    void openFile();
    void pasteFromClipboard();

private Q_SLOTS:
    void updatePasteFromClipboardButton();

private:
    Ui::ImageSelectWidget m_ui;
    ImageSelectTool *const m_imageSelectTool;
};

}
}

#endif
