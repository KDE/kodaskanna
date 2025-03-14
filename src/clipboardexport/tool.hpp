/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_CLIPBOARDEXPORT_TOOL_HPP
#define KODASKANNA_CLIPBOARDEXPORT_TOOL_HPP

// widgets
#include <abstractexporttool.hpp>
// core
#include <scanresult.hpp>

class QAction;

namespace Kodaskanna
{
namespace ClipboardExport
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
    void copyText();
    void copyData();

private:
    QAction *m_copyTextToClipboardAction = nullptr;
    QAction *m_copyDataToClipboardAction = nullptr;

    ScanResult m_scanResult;
};

}
}

#endif
