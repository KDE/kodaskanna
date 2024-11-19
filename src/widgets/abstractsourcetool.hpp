/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_ABSTRACTSOURCETOOL_HPP
#define KODASKANNA_ABSTRACTSOURCETOOL_HPP

// Qt
#include <QObject>

class QWidget;
class QUrl;

namespace Kodaskanna
{
class ScanResult;

class AbstractSourceTool : public QObject
{
    Q_OBJECT

public:
    explicit AbstractSourceTool(QObject *parent = nullptr);

    ~AbstractSourceTool() override;

public: // API to implement
    virtual void setOrigin(const QUrl &origin) = 0;
    virtual QWidget *widget() const = 0;
    virtual void switchToPickView() = 0;
    virtual bool isInPickView() const = 0;

Q_SIGNALS:
    void scanFinished(const ScanResult &scanResult);
    void isInPickViewChanged(bool isInPickView);

private:
};

}

#endif
