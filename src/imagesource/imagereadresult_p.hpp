/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_IMAGEREADRESULT_P_HPP
#define KODASKANNA_IMAGESOURCE_IMAGEREADRESULT_P_HPP

// Qt
#include <QImage>
#include <QSharedData>

namespace Kodaskanna
{

namespace ImageSource
{

class ImageReadResultPrivate : public QSharedData
{
public:
    QImage image;
    bool isSuccess = false;
};

}
}

#endif
