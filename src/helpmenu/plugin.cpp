/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "plugin.hpp"

// own
#include "tool.hpp"

namespace Kodaskanna
{

namespace HelpMenu
{

std::unique_ptr<AbstractMenuTool> createMenuTool()
{
    return std::make_unique<Tool>();
}

}
}
