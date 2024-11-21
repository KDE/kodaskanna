/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_HELPMENU_TOOL_HPP
#define KODASKANNA_HELPMENU_TOOL_HPP

// widgets
#include <abstractmenutool.hpp>

namespace Kodaskanna
{
namespace HelpMenu
{

class Tool : public AbstractMenuTool
{
    Q_OBJECT

public:
    explicit Tool();

    ~Tool() override;

public: // AbstractMenuTool API
    void setupButtonBox(QDialogButtonBox *buttonBox) override;

private:
};

}
}

#endif
