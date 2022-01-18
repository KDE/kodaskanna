/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "imageview.hpp"

// Qt
#include <QLabel>
#include <QPalette>
#include <QPixmap>
#include <QScrollArea>
#include <QVBoxLayout>

namespace Kodaskanna
{
namespace ImageSource
{

// work-around for QLabel not having native proportional scaling of pixmaps
class ProportionalImageLabel : public QLabel
{
public:
    ProportionalImageLabel() = default;

    /// Reinvent setter original method
    void setPixmap(const QPixmap &pixmap)
    {
        m_originalPixmapWidth = pixmap.width();
        m_originalPixmapHeight = pixmap.height();

        adjustContentsMargins();
        QLabel::setPixmap(pixmap);
    }

public: // QWidget API
    void resizeEvent(QResizeEvent *event) override
    {
        adjustContentsMargins();
        QLabel::resizeEvent(event);
    }

private:
    void adjustContentsMargins()
    {
        if ((m_originalPixmapWidth <= 0) || (m_originalPixmapHeight <= 0)) {
            return;
        }

        const int width = this->width();
        const int height = this->height();

        if ((width <= 0) || (height <= 0)) {
            return;
        }

        if (width * m_originalPixmapHeight > height * m_originalPixmapWidth) {
            const int horizontalMargin = (width - (m_originalPixmapWidth * height / m_originalPixmapHeight)) / 2;
            setContentsMargins({horizontalMargin, 0, horizontalMargin, 0});
        } else {
            const int verticalMargin = (height - (m_originalPixmapHeight * width / m_originalPixmapWidth)) / 2;
            setContentsMargins({0, verticalMargin, 0, verticalMargin});
        }
    }

private:
    int m_originalPixmapWidth = 0;
    int m_originalPixmapHeight = 0;
};

ImageView::ImageView(QWidget *parent)
    : QWidget(parent)
    , m_scrollArea(new QScrollArea)
    , m_imageLabel(new ProportionalImageLabel)
{
    m_imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    m_imageLabel->setScaledContents(true);

    m_scrollArea->setBackgroundRole(QPalette::Dark);
    m_scrollArea->setAlignment(Qt::AlignCenter);
    m_scrollArea->setWidget(m_imageLabel);
    m_scrollArea->setWidgetResizable(true);

    auto *layout = new QVBoxLayout;
    layout->setContentsMargins({});
    layout->addWidget(m_scrollArea);
    setLayout(layout);
}

ImageView::~ImageView() = default;

void ImageView::setImage(const QImage &image)
{
    m_image = image;
    m_imageLabel->setPixmap(QPixmap::fromImage(image));
}

}
}
