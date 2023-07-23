/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "abstractdisplaytool.hpp"

namespace Kodaskanna
{

AbstractDisplayTool::AbstractDisplayTool(QObject *parent)
    : QObject(parent)
{
}

AbstractDisplayTool::~AbstractDisplayTool() = default;

}

#include "moc_abstractdisplaytool.cpp"
