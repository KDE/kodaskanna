/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_SCANRESULT_P_HPP
#define KODASKANNA_SCANRESULT_P_HPP

// Qt
#include <QByteArray>
#include <QSharedData>
#include <QString>

namespace Kodaskanna
{

class ScanResultPrivate : public QSharedData
{
public:
    QString text;
    QByteArray bytes;
    bool isSuccess = false;
};

}

#endif
