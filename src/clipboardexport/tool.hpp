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

class QToolButton;
class QMenu;
class QAction;

namespace Kodaskanna
{
namespace ClipboardExport
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
    void copyText();
    void copyData();

private:
    QToolButton *m_clipboardButton;
    QMenu *m_clipboardMenu;
    QAction *m_copyTextToClipboardAction;
    QAction *m_copyDataToClipboardAction;

    ScanResult m_scanResult;
};

}
}

#endif
