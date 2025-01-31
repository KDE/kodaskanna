/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_PLUGIN_HPP
#define KODASKANNA_IMAGESOURCE_PLUGIN_HPP

// Std
#include <memory>

namespace Kodaskanna
{
class AbstractSourceTool;

namespace ImageSource
{

std::unique_ptr<AbstractSourceTool> createSourceTool();

}
}

#endif
