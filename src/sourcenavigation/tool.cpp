/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "tool.hpp"

// kodaskannawidgets
#include <abstractsourcetool.hpp>
// KF
#include <KLocalizedString>
// Qt
#include <QAction>
#include <QDialogButtonBox>
#include <QToolButton>

namespace Kodaskanna
{
namespace SourceNavigation
{

Tool::Tool(AbstractSourceTool *sourceTool)
    : m_sourceTool(sourceTool)
{
}

Tool::~Tool() = default;

void Tool::setupButtonBox(QDialogButtonBox *buttonBox)
{
    if (!m_switchToSourcePickAction) {
        m_switchToSourcePickAction = new QAction(QIcon::fromTheme(QStringLiteral("view-refresh")), i18nc("@action", "Choose Another Source"), this);
        m_switchToSourcePickAction->setEnabled(m_sourceTool->isInPickView());
        connect(m_switchToSourcePickAction, &QAction::triggered,
                m_sourceTool, &AbstractSourceTool::switchToPickView);
        connect(m_sourceTool, &AbstractSourceTool::isInPickViewChanged,
                this, &Tool::handleInPickViewChanged);
    }

    auto *switchToSourcePickButton = new QToolButton(buttonBox);
    switchToSourcePickButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    switchToSourcePickButton->setDefaultAction(m_switchToSourcePickAction);
    buttonBox->addButton(switchToSourcePickButton, QDialogButtonBox::ActionRole);
}

void Tool::handleInPickViewChanged(bool isInPickView)
{
    m_switchToSourcePickAction->setEnabled(!isInPickView);
}

}
}

#include "moc_tool.cpp"
