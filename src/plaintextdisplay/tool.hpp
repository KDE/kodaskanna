/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_PLAINTEXTPREVIEW_TOOL_HPP
#define KODASKANNA_PLAINTEXTPREVIEW_TOOL_HPP

// widgets
#include <abstractdisplaytool.hpp>
// Qt
#include <QImage>
// Std
#include <memory>

namespace Kodaskanna
{
namespace PlainTextDisplay
{
class Widget;

class Tool : public AbstractDisplayTool
{
    Q_OBJECT

public:
    explicit Tool();

    ~Tool() override;

public: // AbstractDisplayTool API
    void setScanResult(const ScanResult &scanResult) override;
    QWidget *widget() const override;

private:
    const std::unique_ptr<Widget> m_widget;
};

}
}

#endif
