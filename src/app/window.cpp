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
// widgets
#include <abstractdisplaytool.hpp>
#include <abstractexporttool.hpp>
#include <abstractsourcetool.hpp>
// KF
#include <KLocalizedString>
// Qt
#include <QUrl>

namespace Kodaskanna
{

Window::Window()
    : QDialog()
{
    setAttribute(Qt::WA_DeleteOnClose);

    m_ui.setupUi(this);

    m_sourceTool = ImageSource::createSourceTool();
    connect(m_sourceTool.get(), &AbstractSourceTool::scanFinished, this, &Window::handleScanFinished);
    m_ui.sourceWidgetStackLayout->addWidget(m_sourceTool->widget());

    m_displayTool = PlainTextDisplay::createDisplayTool(this);
    m_ui.displayWidgetStackLayout->addWidget(m_displayTool->widget());

    m_exportTools = {
        ClipboardExport::createExportTool(this),
        FileExport::createExportTool(this),
    };
    for (auto *tool : std::as_const(m_exportTools)) {
        tool->setupButtonBox(m_ui.buttonBox);
    }

    connect(m_ui.buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accepted);
    connect(m_ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::rejected);
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
    for (auto *tool : std::as_const(m_exportTools)) {
        tool->setScanResult(scanResult);
    }
}

}

#include "moc_window.cpp"
