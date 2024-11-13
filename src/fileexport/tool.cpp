/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "tool.hpp"

// KF
#include <KLocalizedString>
#include <KStandardAction>
// Qt
#include <QAction>
#include <QDialogButtonBox>
#include <QFile>
#include <QFileDialog>
#include <QMenu>
#include <QToolButton>

namespace Kodaskanna
{
namespace FileExport
{

Tool::Tool() = default;

Tool::~Tool() = default;

void Tool::setupButtonBox(QDialogButtonBox *buttonBox)
{
    auto *saveAsMenu = new QMenu(buttonBox);

    if (!m_saveTextAsAction) {
        m_saveTextAsAction = KStandardAction::saveAs(this, &Tool::saveTextAs, this);
        m_saveTextAsAction->setText(i18nc("@action", "Save Text As…"));
        m_saveTextAsAction->setEnabled(false);
    }
    if (!m_saveDataAsAction) {
        m_saveDataAsAction = new QAction(m_saveTextAsAction->icon(), i18nc("@action", "Save Data As…"), this);
        m_saveDataAsAction->setEnabled(false);
        connect(m_saveDataAsAction, &QAction::triggered, this, &Tool::saveDataAs);
    }

    saveAsMenu->addAction(m_saveTextAsAction);
    saveAsMenu->addAction(m_saveDataAsAction);

    auto *saveAsButton = new QToolButton(buttonBox);
    saveAsButton->setMenu(saveAsMenu);
    saveAsButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    saveAsButton->setPopupMode(QToolButton::MenuButtonPopup);
    saveAsButton->setDefaultAction(m_saveTextAsAction);

    buttonBox->addButton(saveAsButton, QDialogButtonBox::ActionRole);
}

void Tool::setScanResult(const ScanResult &scanResult)
{
    m_scanResult = scanResult;

    m_saveTextAsAction->setEnabled(m_scanResult.isSuccess());
    m_saveDataAsAction->setEnabled(m_scanResult.isSuccess());
}

void Tool::saveTextAs()
{
    // TODO: allow select encoding
    const QString localFileName = QFileDialog::getSaveFileName(nullptr, i18nc("@title:window", "Save Text As"));

    if (localFileName.isEmpty()) {
        return;
    }

    QFile file(localFileName);
    if (!file.open(QIODevice::WriteOnly)) {
        // TODO: emit error
        return;
    }

    file.write(m_scanResult.text().toUtf8());
}

void Tool::saveDataAs()
{
    const QString localFileName = QFileDialog::getSaveFileName(nullptr, i18nc("@title:window", "Save Data As"));

    if (localFileName.isEmpty()) {
        return;
    }

    QFile file(localFileName);
    if (!file.open(QIODevice::WriteOnly)) {
        // TODO: emit error
        return;
    }

    file.write(m_scanResult.bytes());
}

}
}

#include "moc_tool.cpp"
