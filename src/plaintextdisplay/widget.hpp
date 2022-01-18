/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_PLAINTEXTPREVIEW_WIDGET_HPP
#define KODASKANNA_PLAINTEXTPREVIEW_WIDGET_HPP

// own
#include "ui_widget.h"
// Qt
#include <QWidget>

namespace Kodaskanna
{
namespace PlainTextDisplay
{

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

public:
    void setText(const QString &text);

private:
    Ui::Widget m_ui;
};

}
}

#endif
