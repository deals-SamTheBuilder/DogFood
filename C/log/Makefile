SRC = ./test.c ./log.c
TARGET := ./log

CC := gcc
RM = rm -rf
LOCAL_CFLAGS = -w -O2 -o
LOCAL_LDFLAGS = 

#############################

.PHONY:all
all: 
	$(CC) $(LOCAL_CFLAGS) $(TARGET) $(LOCAL_LDFLAGS) $(SRC)

.PHONY: clean

clean:
	$(RM) $(TARGET)
