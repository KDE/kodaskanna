# SPDX-FileCopyrightText: 2024 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannasourcenavigation STATIC)

target_sources(kodaskannasourcenavigation PRIVATE
    plugin.cpp
    tool.cpp
)

target_link_libraries(kodaskannasourcenavigation
    PUBLIC
        kodaskannawidgets
    PRIVATE
        KF6::I18n
)
