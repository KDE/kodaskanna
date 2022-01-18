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

Tool::Tool(QObject *parent)
    : AbstractExportTool(parent)
{
}

Tool::~Tool() = default;

void Tool::setupButtonBox(QDialogButtonBox *buttonBox)
{
    m_clipboardMenu = new QMenu(buttonBox);

    m_copyTextToClipboardAction = KStandardAction::copy(this, &Tool::copyText, m_clipboardMenu);
    m_copyTextToClipboardAction->setText(i18nc("@action", "Copy Text to Clipboard"));
    m_copyTextToClipboardAction->setEnabled(false);

    m_copyDataToClipboardAction = new QAction(m_copyTextToClipboardAction->icon(), i18nc("@action", "Copy Data to Clipboard"), m_clipboardMenu);
    m_copyDataToClipboardAction->setEnabled(false);
    connect(m_copyDataToClipboardAction, &QAction::triggered, this, &Tool::copyData);
    m_clipboardMenu->addAction(m_copyTextToClipboardAction);
    m_clipboardMenu->addAction(m_copyDataToClipboardAction);

    m_clipboardButton = new QToolButton(buttonBox);
    m_clipboardButton->setMenu(m_clipboardMenu);
    m_clipboardButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_clipboardButton->setPopupMode(QToolButton::MenuButtonPopup);
    m_clipboardButton->setDefaultAction(m_copyTextToClipboardAction);
    buttonBox->addButton(m_clipboardButton, QDialogButtonBox::ActionRole);
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
