/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_WIDGET_HPP
#define KODASKANNA_IMAGESOURCE_WIDGET_HPP

// own
#include "ui_widget.h"
// Qt
#include <QWidget>

namespace Kodaskanna
{
namespace ImageSource
{
class ImageView;
class ImageSelectWidget;
class ImageSelectTool;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

public:
    void setImage(const QImage &image);
    void showSuccess(const QString &messageText);
    void showError(const QString &messageText);
    void showImageSelect(ImageSelectTool *imageSelectTool);

private:
    Ui::Widget m_ui;
    ImageView *m_imageView;
    ImageSelectWidget *m_imageSelectWidget = nullptr;
};

}
}

#endif
