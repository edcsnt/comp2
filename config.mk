# Copyright (C) 2025 Eduardo Santos <eduardo.experimental@gmail.com>
#
# This file is part of edcsnt/comp2.
#
# edcsnt/comp2 is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at
# your option) any later version.
#
# edcsnt/comp2 is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with edcsnt/comp2. If not, see <https://www.gnu.org/licenses/>.
CC = cc
LD = $(CC)
CPPFLAGS = -D_XOPEN_SOURCE=700
CFLAGS   = -std=c89 -pedantic -Wextra -Wall -Os $(CPPFLAGS)
LDFLAGS  = -s -static
