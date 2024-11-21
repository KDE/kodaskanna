/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_ABSTRACTMENUTOOL_HPP
#define KODASKANNA_ABSTRACTMENUTOOL_HPP

// Qt
#include <QObject>

class QDialogButtonBox;

namespace Kodaskanna
{

class AbstractMenuTool : public QObject
{
    Q_OBJECT

public:
    explicit AbstractMenuTool(QObject *parent = nullptr);

    ~AbstractMenuTool() override;

public: // API to implement
    virtual void setupButtonBox(QDialogButtonBox *buttonBox) = 0;

private:
};

}

#endif
