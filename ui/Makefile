#  Makefile
#  Copyright 2011 Iain Peet
# 
#  This is intended to be included by the root makefile.  Its purpose
#  is to provide a manifest of the source files available in this
#  directory.
# 
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>

# This gets the dir path that the including makefile used for this
# makefile.  This same path should be used for this folders sources.
# NB: immediate substitution is important, since MAKEFILE_LIST is volatile.
UI_DIR:=$(dir $(lastword $(MAKEFILE_LIST)))

# Local source files that should be exported to build
UI_CXX_SRCS:= \
			  imageWidget.cpp \
              asciiDisplay.cpp

# Local headers which declare Qt Objects
UI_QT_HEADS:= \
			  imageWidget.h

# Prepend the directory name
UI_CXX_SRCS:= $(patsubst %,$(UI_DIR)%,$(UI_CXX_SRCS))
UI_QT_HEADS:= $(patsubst %,$(UI_DIR)%,$(UI_QT_HEADS))

# Append this dir's srcs to the global source list
CXX_SRCS:=$(CXX_SRCS) $(UI_CXX_SRCS)
QT_HEADS:=$(QT_HEADS) $(UI_QT_HEADS)

