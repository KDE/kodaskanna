/*
    SPDX-FileCopyrightText: 2024 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_ABSTRACTNAVIGATESOURCETOOL_HPP
#define KODASKANNA_ABSTRACTNAVIGATESOURCETOOL_HPP

// Qt
#include <QObject>

class QDialogButtonBox;

namespace Kodaskanna
{

class AbstractNavigateSourceTool : public QObject
{
    Q_OBJECT

public:
    explicit AbstractNavigateSourceTool(QObject *parent = nullptr);

    ~AbstractNavigateSourceTool() override;

public: // API to implement
    virtual void setupButtonBox(QDialogButtonBox *buttonBox) = 0;

private:
};

}

#endif
