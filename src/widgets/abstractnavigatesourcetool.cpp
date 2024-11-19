/*
    SPDX-FileCopyrightText: 2024 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "abstractnavigatesourcetool.hpp"

namespace Kodaskanna
{

AbstractNavigateSourceTool::AbstractNavigateSourceTool(QObject *parent)
    : QObject(parent)
{
}

AbstractNavigateSourceTool::~AbstractNavigateSourceTool() = default;

}

#include "moc_abstractnavigatesourcetool.cpp"
