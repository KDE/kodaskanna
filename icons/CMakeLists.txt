# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

set(kodaskanna_ICONS
    48-apps-kodaskanna.svg
)

ecm_install_icons(ICONS ${kodaskanna_ICONS} DESTINATION ${KDE_INSTALL_ICONDIR} THEME hicolor)
