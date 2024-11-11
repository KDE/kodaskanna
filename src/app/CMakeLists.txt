# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_executable(kodaskanna)

configure_file(config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/config.hpp @ONLY)

target_sources(kodaskanna PRIVATE
    main.cpp
    window.cpp
)

ki18n_wrap_ui(kodaskanna
    window.ui
)

target_link_libraries(kodaskanna
    kodaskannaimagesource
    kodaskannaplaintextpreview
    kodaskannaclipboardexport
    kodaskannafileexport
    kodaskannawidgets
    kodaskannacore
    KF6::CoreAddons
    KF6::Crash
    KF6::I18n
    Qt6::Widgets
)

install(TARGETS kodaskanna ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS org.kde.kodaskanna.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES org.kde.kodaskanna.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
