VPATH ?= .:$VPATH

SRC = ./test.c

TARGET := ./test

CC := gcc
RM := -rm -rf
CFLAGS := -Wall -O2 -fPIC -rdynamic

#############################

.PHONY: all clean 

all : 
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

clean:
	$(RM) $(TARGET)
