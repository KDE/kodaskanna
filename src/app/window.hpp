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
#include <QList>

class QUrl;

namespace Kodaskanna
{
class AbstractSourceTool;
class AbstractDisplayTool;
class AbstractExportTool;

class Window : public QDialog
{
    Q_OBJECT

public:
    enum OperationMode {

    };

public:
    Window();

    ~Window() override;

public:
    void scanFromFile(const QUrl &fileUrl);

private:
    void handleScanFinished(const ScanResult &scanResult);

private:
    Ui::Window m_ui;

    AbstractSourceTool *m_sourceTool;
    AbstractDisplayTool *m_displayTool;
    QList<AbstractExportTool *> m_exportTools;

    ScanResult m_scanResult;
};

}

#endif
