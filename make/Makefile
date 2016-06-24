# variables

SRC = 
OBJS = main.o print.o
TARGET = test

CC = gcc

#############################

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# 自动推导
main.o: print.h 

print.o: print.c print.h
	$(CC) -c -o print.o print.c

# include
include hi.mk
hello:
	echo $(tips)

clean:
	rm -f $(TARGET) $(OBJS)
