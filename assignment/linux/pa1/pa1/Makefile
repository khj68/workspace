#-----------------------------------------------------------
#
# SSE2030: Introduction to Computer Systems (Fall 2011)
#
# Makefile for PA#1
#
# September 14, 2011.
# CSLab, Sungkyunkwan University
#
#-----------------------------------------------------------

CC		= gcc
CFLAGS	= -g -O -Wall
LDFLAGS	=
RM		= rm

CSRCS	= main.c indexBuilder.c indexPrinter.c
TARGET	= indexBP
OBJECTS	= $(CSRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) -f $(OBJECTS) $(TARGET) *~
