# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(core)
add_subdirectory(widgets)

add_subdirectory(imagesource)
add_subdirectory(plaintextdisplay)

add_subdirectory(clipboardexport)
add_subdirectory(fileexport)

add_subdirectory(konqpopupmenu)
add_subdirectory(purposeplugin)

add_subdirectory(app)

ecm_qt_install_logging_categories(
    EXPORT KODASKANNA
    FILE kodaskanna.categories
    DESTINATION "${KDE_INSTALL_LOGGINGCATEGORIESDIR}"
)
