# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannahelpmenu STATIC)

target_sources(kodaskannahelpmenu PRIVATE
    plugin.cpp
    tool.cpp
)

target_link_libraries(kodaskannahelpmenu
    PUBLIC
        kodaskannawidgets
    PRIVATE
        KF6::CoreAddons
        KF6::XmlGui
)
