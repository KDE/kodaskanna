/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "abstractsourcetool.hpp"

namespace Kodaskanna
{

AbstractSourceTool::AbstractSourceTool(QObject *parent)
    : QObject(parent)
{
}

AbstractSourceTool::~AbstractSourceTool() = default;

}

#include "moc_abstractsourcetool.cpp"
