# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannaclipboardexport STATIC)

target_sources(kodaskannaclipboardexport PRIVATE
    plugin.cpp
    tool.cpp
)

target_link_libraries(kodaskannaclipboardexport
    PUBLIC
        kodaskannawidgets
    PRIVATE
        KF5::WidgetsAddons
        KF5::ConfigWidgets
        KF5::I18n
)
