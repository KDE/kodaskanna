# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannaimagesource STATIC)

ki18n_wrap_ui(kodaskannaimagesource
    imageselectwidget.ui
    widget.ui
)

target_sources(kodaskannaimagesource PRIVATE
    plugin.cpp
    tool.cpp
    loadimagejob.cpp
    readimagefilerunner.cpp
    imagereadresult.cpp
    imageselecttool.cpp
    imageselectwidget.cpp
    imageview.cpp
    widget.cpp
)

target_link_libraries(kodaskannaimagesource
    PUBLIC
        kodaskannawidgets
    PRIVATE
        KF5::KIOCore
        KF5::WidgetsAddons
        KF5::I18n
)
