/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "abstractmenutool.hpp"

namespace Kodaskanna
{

AbstractMenuTool::AbstractMenuTool(QObject *parent)
    : QObject(parent)
{
}

AbstractMenuTool::~AbstractMenuTool() = default;

}

#include "moc_abstractmenutool.cpp"
