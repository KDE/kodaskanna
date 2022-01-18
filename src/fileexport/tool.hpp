/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_FILEEXPORT_TOOL_HPP
#define KODASKANNA_FILEEXPORT_TOOL_HPP

// widgets
#include <abstractexporttool.hpp>
// core
#include <scanresult.hpp>

class QToolButton;
class QMenu;
class QAction;

namespace Kodaskanna
{
namespace FileExport
{

class Tool : public AbstractExportTool
{
    Q_OBJECT

public:
    explicit Tool(QObject *parent = nullptr);

    ~Tool() override;

public: // AbstractExportTool API
    void setupButtonBox(QDialogButtonBox *buttonBox) override;
    void setScanResult(const ScanResult &scanResult) override;

private:
    void saveTextAs();
    void saveDataAs();

private:
    QToolButton *m_saveAsButton;
    QMenu *m_saveAsMenu;
    QAction *m_saveTextAsAction;
    QAction *m_saveDataAsAction;

    ScanResult m_scanResult;
};

}
}

#endif
