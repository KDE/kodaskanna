/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_ABSTRACTEXPORTTOOL_HPP
#define KODASKANNA_ABSTRACTEXPORTTOOL_HPP

// Qt
#include <QObject>

class QDialogButtonBox;

namespace Kodaskanna
{
class ScanResult;

class AbstractExportTool : public QObject
{
    Q_OBJECT

public:
    explicit AbstractExportTool(QObject *parent = nullptr);

    ~AbstractExportTool() override;

public: // API to implement
    virtual void setupButtonBox(QDialogButtonBox *buttonBox) = 0;
    virtual void setScanResult(const ScanResult &scanResult) = 0;

private:
};

}

#endif
