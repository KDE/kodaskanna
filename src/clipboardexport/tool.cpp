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
#include <QApplication>
#include <QClipboard>
#include <QDialogButtonBox>
#include <QMenu>
#include <QMimeData>
#include <QToolButton>

namespace Kodaskanna
{
namespace ClipboardExport
{

Tool::Tool() = default;

Tool::~Tool() = default;

void Tool::setupButtonBox(QDialogButtonBox *buttonBox)
{
    auto *clipboardMenu = new QMenu(buttonBox);

    if (!m_copyTextToClipboardAction) {
        m_copyTextToClipboardAction = KStandardAction::copy(this, &Tool::copyText, this);
        m_copyTextToClipboardAction->setText(i18nc("@action", "Copy Text to Clipboard"));
        m_copyTextToClipboardAction->setEnabled(false);
    }
    if (!m_copyDataToClipboardAction) {
        m_copyDataToClipboardAction = new QAction(m_copyTextToClipboardAction->icon(), i18nc("@action", "Copy Data to Clipboard"), this);
        m_copyDataToClipboardAction->setEnabled(false);
        connect(m_copyDataToClipboardAction, &QAction::triggered, this, &Tool::copyData);
    }

    clipboardMenu->addAction(m_copyTextToClipboardAction);
    clipboardMenu->addAction(m_copyDataToClipboardAction);

    auto *clipboardButton = new QToolButton(buttonBox);
    clipboardButton->setMenu(clipboardMenu);
    clipboardButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    clipboardButton->setPopupMode(QToolButton::MenuButtonPopup);
    clipboardButton->setDefaultAction(m_copyTextToClipboardAction);

    buttonBox->addButton(clipboardButton, QDialogButtonBox::ActionRole);
}

void Tool::setScanResult(const ScanResult &scanResult)
{
    m_scanResult = scanResult;

    m_copyTextToClipboardAction->setEnabled(m_scanResult.isSuccess());
    m_copyDataToClipboardAction->setEnabled(m_scanResult.isSuccess());
}

void Tool::copyText()
{
    QApplication::clipboard()->setText(m_scanResult.text());
}

void Tool::copyData()
{
    auto *mimeData = new QMimeData;
    mimeData->setData(QStringLiteral("application/octet-stream"), m_scanResult.bytes());
    QApplication::clipboard()->setMimeData(mimeData);
}

}
}

#include "moc_tool.cpp"
