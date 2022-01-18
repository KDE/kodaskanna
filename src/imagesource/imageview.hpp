/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_IMAGEVIEW_HPP
#define KODASKANNA_IMAGESOURCE_IMAGEVIEW_HPP

// Qt
#include <QImage>
#include <QWidget>

class QScrollArea;

namespace Kodaskanna
{
namespace ImageSource
{
class ProportionalImageLabel;

class ImageView : public QWidget
{
    Q_OBJECT

public:
    explicit ImageView(QWidget *parent = nullptr);

    ~ImageView() override;

public:
    void setImage(const QImage &image);

private:
    QScrollArea *m_scrollArea;
    ProportionalImageLabel *m_imageLabel;

    QImage m_image;
};

}
}

#endif
