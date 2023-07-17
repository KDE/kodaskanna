/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "widget.hpp"

// own
#include "imageselectwidget.hpp"
#include "imageview.hpp"
// Qt
#include <QImage>

namespace Kodaskanna
{
namespace ImageSource
{

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_imageView(new ImageView(this))
{
    m_ui.setupUi(this);
    m_ui.widgetStackLayout->addWidget(m_imageView);
}

Widget::~Widget() = default;

void Widget::setImage(const QImage &image)
{
    m_imageView->setImage(image);
    m_ui.widgetStackLayout->setCurrentWidget(m_imageView);
}

void Widget::showImageSelect(ImageSelectTool *imageSelectTool)
{
    if (m_imageSelectWidget) {
        return;
    }

    m_imageSelectWidget = new ImageSelectWidget(imageSelectTool, this);
    m_ui.widgetStackLayout->addWidget(m_imageSelectWidget);
    m_ui.widgetStackLayout->setCurrentWidget(m_imageSelectWidget);
}

void Widget::showSuccess(const QString &messageText)
{
    m_ui.messageWidget->setMessageType(KMessageWidget::Positive);
    m_ui.messageWidget->setText(messageText);
    m_ui.messageWidget->animatedShow();
}

void Widget::showError(const QString &messageText)
{
    m_ui.messageWidget->setMessageType(KMessageWidget::Error);
    m_ui.messageWidget->setText(messageText);
    m_ui.messageWidget->animatedShow();
}

}
}

#include "moc_widget.cpp"
