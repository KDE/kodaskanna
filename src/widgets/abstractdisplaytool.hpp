/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_ABSTRACTDISPLAYTOOL_HPP
#define KODASKANNA_ABSTRACTDISPLAYTOOL_HPP

// Qt
#include <QObject>

class QWidget;

namespace Kodaskanna
{
class ScanResult;

class AbstractDisplayTool : public QObject
{
    Q_OBJECT

public:
    explicit AbstractDisplayTool(QObject *parent = nullptr);

    ~AbstractDisplayTool() override;

public: // API to implement
    virtual void setScanResult(const ScanResult &scanResult) = 0;
    virtual QWidget *widget() const = 0;

private:
};

}

#endif
