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

class QAction;

namespace Kodaskanna
{
namespace FileExport
{

class Tool : public AbstractExportTool
{
    Q_OBJECT

public:
    explicit Tool();

    ~Tool() override;

public: // AbstractExportTool API
    void setupButtonBox(QDialogButtonBox *buttonBox) override;
    void setScanResult(const ScanResult &scanResult) override;

private:
    void saveTextAs();
    void saveDataAs();

private:
    QAction *m_saveTextAsAction = nullptr;
    QAction *m_saveDataAsAction = nullptr;

    ScanResult m_scanResult;
};

}
}

#endif
