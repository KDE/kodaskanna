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
        KF5::WidgetsAddons
        KF5::ConfigWidgets
        KF5::I18n
)
