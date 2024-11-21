/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_HELPMENU_PLUGIN_HPP
#define KODASKANNA_HELPMENU_PLUGIN_HPP

// Std
#include <memory>

namespace Kodaskanna
{
class AbstractMenuTool;

namespace HelpMenu
{

std::unique_ptr<AbstractMenuTool> createMenuTool();

}
}

#endif
