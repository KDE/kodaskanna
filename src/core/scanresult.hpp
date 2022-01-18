/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_SCANRESULT_HPP
#define KODASKANNA_SCANRESULT_HPP

// Qt
#include <QExplicitlySharedDataPointer>
#include <QMetaType>

class QByteArray;
class QString;

namespace Kodaskanna
{

class ScanResultPrivate;

class ScanResult
{
public:
    ScanResult();
    ScanResult(const ScanResult &other);
    ~ScanResult();

    ScanResult &operator=(const ScanResult &other);

public:
    const QString &text() const;
    const QByteArray &bytes() const;
    bool isSuccess() const;

private:
    explicit ScanResult(ScanResultPrivate *dd);

private:
    friend class ScanImageRunner;
    QExplicitlySharedDataPointer<ScanResultPrivate> d;
};

}

Q_DECLARE_METATYPE(Kodaskanna::ScanResult)

#endif
