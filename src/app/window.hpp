/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_WINDOW_HPP
#define KODASKANNA_WINDOW_HPP

#include "ui_window.h"
// core
#include <scanresult.hpp>
// Qt
#include <QDialog>
// Std
#include <memory>
#include <vector>

class QUrl;

namespace Kodaskanna
{
class AbstractSourceTool;
class AbstractDisplayTool;
class AbstractExportTool;
class AbstractMenuTool;
class AbstractNavigateSourceTool;

class Window : public QDialog
{
    Q_OBJECT

public:
    enum Modus {
        DefaultModus = 0,
        OneScanModus = 1,
    };

public:
    explicit Window(Modus modus);

    ~Window() override;

public:
    void scanFromFile(const QUrl &fileUrl);

private:
    void handleScanFinished(const ScanResult &scanResult);

private:
    Ui::Window m_ui;

    std::unique_ptr<AbstractSourceTool> m_sourceTool;
    std::unique_ptr<AbstractDisplayTool> m_displayTool;
    std::unique_ptr<AbstractNavigateSourceTool> m_sourceNavigationTool;
    std::vector<std::unique_ptr<AbstractExportTool>> m_exportTools;
    std::unique_ptr<AbstractMenuTool> m_helpMenuTool;

    ScanResult m_scanResult;
};

}

#endif
