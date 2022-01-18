/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_CLIPBOARDEXPORT_PLUGIN_HPP
#define KODASKANNA_CLIPBOARDEXPORT_PLUGIN_HPP

class QObject;

namespace Kodaskanna
{
class AbstractExportTool;

namespace ClipboardExport
{

AbstractExportTool *createExportTool(QObject *parent = nullptr);

}
}

#endif
