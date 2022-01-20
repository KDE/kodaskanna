/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "widget.hpp"

// KF
#include <KTextToHTML>

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
    // Until we have proper MIME type detection, simply always try to add links to anything that could be linked
    // TODO: does KTextToHTML change text only in a way that QTextEdit::toPlainText() still delivers the original one?
    const QString textAsHtml = KTextToHTML::convertToHtml(text, {KTextToHTML::PreserveSpaces | KTextToHTML::ConvertPhoneNumbers});
    m_ui.plainTextView->setHtml(textAsHtml);
}

}
}
