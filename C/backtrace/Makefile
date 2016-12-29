VPATH ?= .:$VPATH

SRC = ./main.c ./bt.c

TARGET := ./bt

CC := gcc
RM := -rm -rf
CFLAGS := -Wall -O2 -I . -rdynamic

#############################

.PHONY: all clean 

all : 
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

clean:
	$(RM) $(TARGET)
