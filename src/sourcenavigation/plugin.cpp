/*
    SPDX-FileCopyrightText: 2024 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "plugin.hpp"

// own
#include "tool.hpp"

namespace Kodaskanna
{

namespace SourceNavigation
{

std::unique_ptr<AbstractNavigateSourceTool> createNavigateSourceTool(AbstractSourceTool *sourceTool)
{
    return std::make_unique<Tool>(sourceTool);
}

}
}
