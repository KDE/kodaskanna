/*
    SPDX-FileCopyrightText: 2024 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_NAVIGATESOURCETOOL_TOOL_HPP
#define KODASKANNA_NAVIGATESOURCETOOL_TOOL_HPP

// widgets
#include <abstractnavigatesourcetool.hpp>

class QAction;

namespace Kodaskanna
{
class AbstractSourceTool;

namespace SourceNavigation
{

class Tool : public AbstractNavigateSourceTool
{
    Q_OBJECT

public:
    explicit Tool(AbstractSourceTool *sourceTool);

    ~Tool() override;

public: // AbstractMenuTool API
    void setupButtonBox(QDialogButtonBox *buttonBox) override;

private Q_SLOTS:
    void handleInPickViewChanged(bool isInPickView);

private:
    AbstractSourceTool * const m_sourceTool;
    QAction *m_switchToSourcePickAction = nullptr;
};

}
}

#endif
