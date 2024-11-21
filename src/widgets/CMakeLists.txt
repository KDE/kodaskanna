# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannawidgets STATIC)

target_sources(kodaskannawidgets PRIVATE
    abstractsourcetool.cpp
    abstractdisplaytool.cpp
    abstractexporttool.cpp
    abstractnavigatesourcetool.cpp
    abstractmenutool.cpp
)

target_link_libraries(kodaskannawidgets
    PUBLIC
        kodaskannacore
        Qt6::Widgets
)
