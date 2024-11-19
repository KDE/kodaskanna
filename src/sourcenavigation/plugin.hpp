/*
    SPDX-FileCopyrightText: 2024 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_NAVIGATESOURCETOOL_PLUGIN_HPP
#define KODASKANNA_NAVIGATESOURCETOOL_PLUGIN_HPP

// Std
#include <memory>

namespace Kodaskanna
{

class AbstractSourceTool;
class AbstractNavigateSourceTool;

namespace SourceNavigation
{

std::unique_ptr<AbstractNavigateSourceTool> createNavigateSourceTool(AbstractSourceTool *sourceTool);

}
}

#endif
