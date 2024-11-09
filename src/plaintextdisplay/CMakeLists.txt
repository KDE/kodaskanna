# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannaplaintextpreview STATIC)

ki18n_wrap_ui(kodaskannaplaintextpreview
    widget.ui
)

target_sources(kodaskannaplaintextpreview PRIVATE
    plugin.cpp
    tool.cpp
    widget.cpp
)

target_link_libraries(kodaskannaplaintextpreview
    PUBLIC
        kodaskannawidgets
    PRIVATE
        KF6::CoreAddons
        KF6::I18n
)
