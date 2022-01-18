/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_PLUGIN_HPP
#define KODASKANNA_IMAGESOURCE_PLUGIN_HPP

class QObject;

namespace Kodaskanna
{
class AbstractSourceTool;

namespace ImageSource
{

AbstractSourceTool *createSourceTool(QObject *parent = nullptr);

}
}

#endif
