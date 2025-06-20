CC = cc
LD = $(CC)
CPPFLAGS = -D_XOPEN_SOURCE=700
CFLAGS   = -std=c89 -pedantic -Wextra -Wall -Os $(CPPFLAGS)
LDFLAGS  = -s -static
