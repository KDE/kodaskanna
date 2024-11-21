/*
    SPDX-FileCopyrightText: 2022, 2024 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "tool.hpp"

// KF
#include <KHelpMenu>
#include <KAboutData>
// Qt
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMenu>

namespace Kodaskanna
{
namespace HelpMenu
{

Tool::Tool() = default;

Tool::~Tool() = default;

void Tool::setupButtonBox(QDialogButtonBox *buttonBox)
{
    QPushButton *helpButton = buttonBox->addButton(QDialogButtonBox::Help);
    helpButton->setAutoDefault(false);

#if KXMLGUI_VERSION >= QT_VERSION_CHECK(6, 9, 0)
    auto *helpMenu = new KHelpMenu(helpButton, KAboutData::applicationData());
    helpMenu->setShowWhatsThis(false);
#else
    auto *helpMenu = new KHelpMenu(helpButton, KAboutData::applicationData(), false);
#endif
    // we have no help docs currently, do same trick as KRename (as of Nov 24)
    // TODO: fix KHelpMenu to have somethin like setShowHelpContents
    helpMenu->menu()->removeAction(helpMenu->action(KHelpMenu::menuHelpContents));
    helpButton->setMenu(helpMenu->menu());
}

}
}

#include "moc_tool.cpp"
