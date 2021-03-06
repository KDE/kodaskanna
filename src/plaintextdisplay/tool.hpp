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

namespace Kodaskanna
{
namespace PlainTextDisplay
{
class Widget;

class Tool : public AbstractDisplayTool
{
    Q_OBJECT

public:
    explicit Tool(QObject *parent = nullptr);

    ~Tool() override;

public: // AbstractDisplayTool API
    void setScanResult(const ScanResult &scanResult) override;
    QWidget *widget() override;

private:
    Widget *m_widget;
};

}
}

#endif
