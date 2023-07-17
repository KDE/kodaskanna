/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "abstractexporttool.hpp"

namespace Kodaskanna
{

AbstractExportTool::AbstractExportTool(QObject *parent)
    : QObject(parent)
{
}

AbstractExportTool::~AbstractExportTool() = default;

void AbstractExportTool::setupButtonBox(QDialogButtonBox *buttonBox)
{
    Q_UNUSED(buttonBox);
}

}

#include "moc_abstractexporttool.cpp"
