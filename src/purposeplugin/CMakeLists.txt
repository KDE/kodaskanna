# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_definitions(-DTRANSLATION_DOMAIN=\"kodaskanna\")

add_library(purposeplugin MODULE)
set_target_properties(purposeplugin PROPERTIES
    OUTPUT_NAME kodaskannaplugin
)

target_sources(purposeplugin PRIVATE
    plugin.cpp
    launchjob.cpp
)

target_link_libraries(purposeplugin
    KF6::Purpose
    KF6::KIOGui
    KF6::I18n
)

install(TARGETS purposeplugin DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf6/purpose)
