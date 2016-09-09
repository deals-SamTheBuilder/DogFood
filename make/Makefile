# variables

VPATH = ~/Desktop/DogFood/make/:. #当前目录找不到文件时,去指定路径查找

SRC = ./main.c ./print.c
OBJS := main.o print.o # 加了:前面的变量不能使用后面的变量
TARGET := test

CC := gcc
RM = rm -rf
CFLAGS = -Wall -O2 -I ./ -o # 编译器参数,C使用
CXXFLAGS = # C++使用
LDFLAGS =  # 链接器参数
LDSHFLAGS = -fPIC -shared # 动态库编译参数

#############################

# 显示指明伪目标,避免和文件重名
.PHONY:all hello install clean
all:
	$(CC) $(CFLAGS) $(TARGET) $(LDFLAGS) $(SRC)

#################
define hi 
	echo $(tips)
endef

# include
include hi.mk
################

hello:
	$(hi)

install:

clean:
	$(RM)
