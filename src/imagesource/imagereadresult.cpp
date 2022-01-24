/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "imagereadresult.hpp"
#include "imagereadresult_p.hpp"

namespace Kodaskanna
{

namespace ImageSource
{

ImageReadResult::ImageReadResult()
    : d(new ImageReadResultPrivate)
{
}

ImageReadResult::ImageReadResult(const ImageReadResult &other) = default;

ImageReadResult::ImageReadResult(ImageReadResultPrivate *dd)
    : d(dd)
{
}

ImageReadResult::~ImageReadResult() = default;

ImageReadResult &ImageReadResult::operator=(const ImageReadResult &other)
{
    d = other.d;
    return *this;
}

bool ImageReadResult::isSuccess() const
{
    return d->isSuccess;
}

const QImage &ImageReadResult::image() const
{
    return d->image;
}

}
}
