# SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>
#
# SPDX-License-Identifier: BSD-3-Clause

add_library(kodaskannacore STATIC)

target_sources(kodaskannacore PRIVATE
    scanimagerunner.cpp
    scanresult.cpp
)

if(ZXing_VERSION VERSION_GREATER_EQUAL 2.3)
    # ZXing::ImageView inline methods throw exceptions
    kde_source_files_enable_exceptions(scanimagerunner.cpp)
endif()

target_link_libraries(kodaskannacore
    PUBLIC
        Qt6::Gui
    PRIVATE
        ZXing::Core
)
