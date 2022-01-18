#! /usr/bin/env bash
# SPDX-License-Identifier: CC0-1.0
# SPDX-FileCopyrightText: none

$EXTRACTRC `find . -name \*.ui -o -name \*.rc -o -name \*.kcfg` >> rc.cpp
$XGETTEXT `find . -name \*.cpp` -o $podir/kodaskanna.pot
rm -f rc.cpp
