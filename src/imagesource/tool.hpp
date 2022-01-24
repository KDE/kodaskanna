/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_TOOL_HPP
#define KODASKANNA_IMAGESOURCE_TOOL_HPP

// widgets
#include <abstractsourcetool.hpp>
// Std
#include <memory>

class KJob;
class QImage;

namespace Kodaskanna
{

class ScanResult;

namespace ImageSource
{
class ImageSelectTool;
class Widget;

class Tool : public AbstractSourceTool
{
    Q_OBJECT

public:
    explicit Tool(QObject *parent = nullptr);

    ~Tool() override;

public:
    void setImage(const QImage &image);

public: // AbstractSourceTool API
    void setOrigin(const QUrl &origin) override;
    QWidget *widget() override;

private:
    void handleImageLoadResult(KJob *job);
    void handleScanFinished(const ScanResult &scanResult);

private:
    std::unique_ptr<ImageSelectTool> m_imageSelectTool;
    Widget *m_widget;
};

}
}

#endif
