/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "scanresult.hpp"
#include "scanresult_p.hpp"

namespace Kodaskanna
{

ScanResult::ScanResult()
    : d(new ScanResultPrivate)
{
}

ScanResult::ScanResult(const ScanResult &other) = default;

ScanResult::ScanResult(ScanResultPrivate *dd)
    : d(dd)
{
}

ScanResult::~ScanResult() = default;

ScanResult &ScanResult::operator=(const ScanResult &other)
{
    d = other.d;
    return *this;
}

bool ScanResult::isSuccess() const
{
    return d->isSuccess;
}

const QString &ScanResult::text() const
{
    return d->text;
}

const QByteArray &ScanResult::bytes() const
{
    return d->bytes;
}

}
