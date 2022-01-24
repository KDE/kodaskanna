/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_IMAGEREADRESULT_HPP
#define KODASKANNA_IMAGESOURCE_IMAGEREADRESULT_HPP

// Qt
#include <QExplicitlySharedDataPointer>
#include <QMetaType>

class QImage;

namespace Kodaskanna
{

namespace ImageSource
{

class ImageReadResultPrivate;

class ImageReadResult
{
public:
    ImageReadResult();
    ImageReadResult(const ImageReadResult &other);
    ~ImageReadResult();

    ImageReadResult &operator=(const ImageReadResult &other);

public:
    const QImage &image() const;
    bool isSuccess() const;

private:
    explicit ImageReadResult(ImageReadResultPrivate *dd);

private:
    friend class ReadImageFileRunner;
    QExplicitlySharedDataPointer<ImageReadResultPrivate> d;
};

}
}

Q_DECLARE_METATYPE(Kodaskanna::ImageSource::ImageReadResult)

#endif
