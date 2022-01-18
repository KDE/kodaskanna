/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "widget.hpp"

namespace Kodaskanna
{
namespace PlainTextDisplay
{

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
}

Widget::~Widget() = default;

void Widget::setText(const QString &text)
{
    m_ui.plainTextView->setPlainText(text);
}

}
}
