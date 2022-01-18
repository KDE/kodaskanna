/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "tool.hpp"

// own
#include "widget.hpp"
// core
#include <scanresult.hpp>

namespace Kodaskanna
{
namespace PlainTextDisplay
{

Tool::Tool(QObject *parent)
    : AbstractDisplayTool(parent)
    , m_widget(new Widget)
{
    m_widget->setEnabled(false);
}

Tool::~Tool() = default;

void Tool::setScanResult(const ScanResult &scanResult)
{
    m_widget->setEnabled(scanResult.isSuccess());
    m_widget->setText(scanResult.text());
}

QWidget *Tool::widget()
{
    return m_widget;
}

}
}
