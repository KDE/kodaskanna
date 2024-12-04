<!--
SPDX-FileCopyrightText: 2024 Friedrich W. H. Kossebau <kossebau@kde.org>
SPDX-License-Identifier: CC0-1.0
-->

# Kodaskanna

A multi-format 1D/2D code scanner

License: GNU Lesser General Public License, v2.1 or later

Copyright: 2022, 2024 Friedrich W. H. Kossebau <kossebau@kde.org>

Author/Maintainer: Friedrich W. H. Kossebau <kossebau@kde.org>

Bug reports: [bugs.kde.org](https://bugs.kde.org/enter_bug.cgi?format=guided&amp;product=kodaskanna)

Homepage: [apps.kde.org/kodaskanna](https://apps.kde.org/kodaskanna)

## Overview

Kodaskanna is as of now a utility program for reading data from 1D/2D codes
(e.g. QR codes or bar codes) and making the data available for further processing.

Current feature set:

- scanning 1D/2D codes in static images:<br/>
  The image input files (can be also non-local ones) can be either passed as argument on the command line or manually selected via a file picker, pasted from the clipboard, dropped by DnD or be piped from stdin.
- extracted content can be exported to the clipboard or as a file

Current integration with service systems:
- Dolphin context menu, "Scan data code" action entry with image files ([src/konqpopupmenu/](src/konqpopupmenu/))
- KDE Purpose, by an "Export" plugin ([src/purposeplugin/](src/purposeplugin/))

The code reading itself is powered by the [ZXing-C++](https://github.com/zxing-cpp/zxing-cpp) library.

For now this software is worked on when there are actual personal needs not covered by other solutions. Any ideas what could be done for further product development (see below) stay ideas without any schedule.

## Long-term Vision

The long-term vision for Kodaskanna is to be an simple utility to integrate in 
workflows where some data processing expects a data blob (or a series of 
those) to be taken from a machine readable source by the user.

It should have reusable general purpose extensions both for reading all kind of encoded data in all kind of sources (e.g. graphical, acoustical) or straight from dedicated input devices, as well as for validating and previewing the extracted data for the expected data format.

The invoking instance should be able to filter/define what is possible.

The utility should be usable both in-process as out-
of-process, and ideally itself be replaceable by other solutions providing the 
same interface.
