/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "scanimagerunner.hpp"

// own
#include "scanresult.hpp"
#include "scanresult_p.hpp"
// ZXing
#include <ZXing/ReadBarcode.h>
#include <ZXing/ZXVersion.h>

#define ZXING_VERSION ((ZXING_VERSION_MAJOR<<16)|(ZXING_VERSION_MINOR<<8)|(ZXING_VERSION_PATCH))

namespace Kodaskanna
{

ScanImageRunner::ScanImageRunner(const QImage &image)
    : m_image(image)
{
}

ZXing::ImageFormat zxingImageFormatFromQImage(const QImage &image)
{
    switch (image.format()) {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
        return ZXing::ImageFormat::BGRX;
#else
        return ZXing::ImageFormat::XRGB;
#endif
    case QImage::Format_RGB888:
        return ZXing::ImageFormat::RGB;
    case QImage::Format_RGBX8888:
    case QImage::Format_RGBA8888:
        return ZXing::ImageFormat::RGBX;
    case QImage::Format_Grayscale8:
        return ZXing::ImageFormat::Lum;
    default:
        return ZXing::ImageFormat::None;
    }
}

#if ZXING_VERSION >= QT_VERSION_CHECK(2, 2, 0)
ZXing::Result readBarcode(const QImage &image, const ZXing::ReaderOptions &readerOptions)
{
    return ZXing::ReadBarcode({image.bits(), image.width(), image.height(), zxingImageFormatFromQImage(image), static_cast<int>(image.bytesPerLine())}, readerOptions);
}
#else
ZXing::Result readBarcode(const QImage &image, ZXing::DecodeHints decodeHints)
{
    return ZXing::ReadBarcode({image.bits(), image.width(), image.height(), zxingImageFormatFromQImage(image), static_cast<int>(image.bytesPerLine())}, decodeHints);
}
#endif

void ScanImageRunner::run()
{
#if ZXING_VERSION >= QT_VERSION_CHECK(2, 2, 0)
    ZXing::ReaderOptions readerOptions;
    readerOptions.setFormats(ZXing::BarcodeFormat::Any);

    const bool isSupportedQImageFormat = (zxingImageFormatFromQImage(m_image) == ZXing::ImageFormat::None);
    ZXing::Result result =
        isSupportedQImageFormat ? readBarcode(m_image.convertToFormat(QImage::Format_RGBX8888), readerOptions) : readBarcode(m_image, readerOptions);
#else
    ZXing::DecodeHints decodeHints;
    decodeHints.setFormats(ZXing::BarcodeFormat::Any);

    const bool isSupportedQImageFormat = (zxingImageFormatFromQImage(m_image) == ZXing::ImageFormat::None);
    ZXing::Result result =
        isSupportedQImageFormat ? readBarcode(m_image.convertToFormat(QImage::Format_RGBX8888), decodeHints) : readBarcode(m_image, decodeHints);
#endif

    auto *resultData = new ScanResultPrivate;
    ScanResult scanResult(resultData);

    resultData->isSuccess = result.isValid();
    if (resultData->isSuccess) {
        resultData->text = QString::fromStdString(result.text());
        resultData->bytes = QByteArray(reinterpret_cast<const char *>(result.bytes().data()), result.bytes().size());
    }

    Q_EMIT scanFinished(scanResult);
}

}

#include "moc_scanimagerunner.cpp"
