/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_PLAINTEXTPREVIEW_PLUGIN_HPP
#define KODASKANNA_PLAINTEXTPREVIEW_PLUGIN_HPP

class QObject;

namespace Kodaskanna
{
class AbstractDisplayTool;

namespace PlainTextDisplay
{

AbstractDisplayTool *createDisplayTool(QObject *parent = nullptr);

}
}

#endif
