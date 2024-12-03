/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "window.hpp"

// plugins
#include "../clipboardexport/plugin.hpp"
#include "../fileexport/plugin.hpp"
#include "../imagesource/plugin.hpp"
#include "../plaintextdisplay/plugin.hpp"
#include "../sourcenavigation/plugin.hpp"
#include "../helpmenu/plugin.hpp"
// widgets
#include <abstractdisplaytool.hpp>
#include <abstractexporttool.hpp>
#include <abstractsourcetool.hpp>
#include <abstractnavigatesourcetool.hpp>
#include <abstractmenutool.hpp>
// KF
#include <KLocalizedString>
// Qt
#include <QCoreApplication>
#include <QKeySequence>
#include <QShortcut>
#include <QUrl>

namespace Kodaskanna
{

Window::Window(Modus modus)
    : QDialog()
{
    setAttribute(Qt::WA_DeleteOnClose);

    m_ui.setupUi(this);

    m_sourceTool = ImageSource::createSourceTool();
    connect(m_sourceTool.get(), &AbstractSourceTool::scanFinished, this, &Window::handleScanFinished);
    m_ui.sourceWidgetStackLayout->addWidget(m_sourceTool->widget());

    m_displayTool = PlainTextDisplay::createDisplayTool();
    m_ui.displayWidgetStackLayout->addWidget(m_displayTool->widget());

    if (modus != OneScanModus) {
        m_sourceNavigationTool = SourceNavigation::createNavigateSourceTool(m_sourceTool.get());
        m_sourceNavigationTool->setupButtonBox(m_ui.buttonBox);
    }

    m_exportTools.reserve(2);
    m_exportTools.emplace_back(ClipboardExport::createExportTool());
    m_exportTools.emplace_back(FileExport::createExportTool());
    for (const auto& tool : std::as_const(m_exportTools)) {
        tool->setupButtonBox(m_ui.buttonBox);
    }

    if (modus != OneScanModus) {
        m_helpMenuTool = HelpMenu::createMenuTool();
        m_helpMenuTool->setupButtonBox(m_ui.buttonBox);
    }

    connect(m_ui.buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accepted);
    connect(m_ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::rejected);

    if (modus != OneScanModus) {
        // TODO: turn into tool? or treat as dialog tuning? also close dialog instead only?
        // added here for now to give users the feature
        auto* quitShortcut = new QShortcut(QKeySequence::Quit, this);
        connect(quitShortcut, &QShortcut::activated, qApp, &QCoreApplication::quit);
    }
}

Window::~Window()
{
    QWidget *displayWidget = m_displayTool->widget();
    m_ui.displayWidgetStackLayout->removeWidget(displayWidget);
    displayWidget->setParent(nullptr);

    QWidget *sourceWidget = m_sourceTool->widget();
    m_ui.sourceWidgetStackLayout->removeWidget(sourceWidget);
    sourceWidget->setParent(nullptr);
}

void Window::scanFromFile(const QUrl &fileUrl)
{
    m_sourceTool->setOrigin(fileUrl);
}

void Window::handleScanFinished(const ScanResult &scanResult)
{
    m_scanResult = scanResult;
    m_displayTool->setScanResult(scanResult);
    for (const auto& tool : std::as_const(m_exportTools)) {
        tool->setScanResult(scanResult);
    }
}

}

#include "moc_window.cpp"
