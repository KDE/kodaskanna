# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannafileexport STATIC)

target_sources(kodaskannafileexport PRIVATE
    plugin.cpp
    tool.cpp
)

target_link_libraries(kodaskannafileexport
    PUBLIC
        kodaskannawidgets
    PRIVATE
        KF6::WidgetsAddons
        KF6::ConfigWidgets
        KF6::I18n
)
