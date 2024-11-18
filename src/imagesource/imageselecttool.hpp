/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_IMAGESOURCE_IMAGESELECTTOOL_HPP
#define KODASKANNA_IMAGESOURCE_IMAGESELECTTOOL_HPP

class QMimeData;

namespace Kodaskanna
{
namespace ImageSource
{
class Tool;

class ImageSelectTool
{
public:
    explicit ImageSelectTool(Tool *tool);

public:
    bool canHandleMimeData(const QMimeData *mimeData) const;
    bool handleMimeData(const QMimeData *mimeData);
    void openFile();

private:
    Tool *const m_tool;
};

}
}

#endif
