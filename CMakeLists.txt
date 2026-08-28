# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)

project(Kodaskanna VERSION "0.2.3")

set(QT_MIN_VERSION "6.5")
set(KF_MIN_VERSION "6.0")

find_package(ECM ${KF_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

include(ECMDeprecationSettings)
include(ECMInstallIcons)
include(ECMQtDeclareLoggingCategory)
include(KDEClangFormat)
include(FeatureSummary)

find_package(Qt6 ${QT_MIN_VERSION} REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    MultimediaWidgets
)

find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    Crash
    WidgetsAddons
    ConfigWidgets
    KIO
    Purpose
    XmlGui
    I18n
)

foreach(ver 3.0 2.0)
    find_package(ZXing ${ver} QUIET)
    if (${ZXing_FOUND})
        break()
    endif()
endforeach()
set_package_properties(ZXing PROPERTIES
    TYPE REQUIRED
)

ecm_set_disabled_deprecation_versions(
    QT 6.10
    KF 6.29
)

add_subdirectory(src)
add_subdirectory(icons)

ki18n_install(po)

file(GLOB_RECURSE ALL_CLANG_FORMAT_SOURCE_FILES *.cpp *.hpp)
kde_clang_format(${ALL_CLANG_FORMAT_SOURCE_FILES})

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
