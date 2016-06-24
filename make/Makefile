# variables

VPATH = ~/Desktop/DogFood/make/:. #当当前目录找不到文件时,去指定路径查找

SRC = 
OBJS := main.o print.o #加了:前面的变量不能使用后面的变量
TARGET := test
TARGET1 := test-bak

CC := gcc
RM = rm -rf
LOCAL_CFLAGS = -o #编译器参数
LOCAL_LDFLAGS =  #链接器参数

#############################

.PHONY:all
all: $(TARGET) $(TARGET1)

$(TARGET): $(OBJS)
	$(CC) $(LOCAL_CFLAGS) $(TARGET) $(OBJS)

$(TARGET1) : 
	$(CC) $(LOCAL_CFLAGS) $(TARGET1) $(OBJS)

define hi 
	echo $(tips)
endef

# 显示指明伪目标,避免和文件重名
.PHONY: clean hello install

# include
include hi.mk
hello:
	$(hi)

install:
	mkdir bin
	mv $(TARGET) $(TARGET1) bin/

clean:
	$(RM) $(TARGET) $(OBJS) $(TARGET1) bin/
