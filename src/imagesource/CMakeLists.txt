# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannaimagesource STATIC)

ecm_qt_declare_logging_category(kodaskannaimagesource
    HEADER "logging.hpp"
    IDENTIFIER "LOG_KODASKANNA_IMAGESOURCE"
    CATEGORY_NAME "kodaskanna.imagesource"
    DESCRIPTION "Kodaskanna ImageSource library"
    EXPORT KODASKANNA
)

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
        KF6::KIOCore
        KF6::WidgetsAddons
        KF6::I18n
)
