# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannacore STATIC)

target_sources(kodaskannacore PRIVATE
    scanimagerunner.cpp
    scanresult.cpp
)

target_link_libraries(kodaskannacore
    PUBLIC
        Qt6::Gui
    PRIVATE
        ZXing::Core
)
