# variables

VPATH = ~/Desktop/DogFood/make/:. #当当前目录找不到文件时,去指定路径查找

SRC = 
OBJS := main.o print.o #加了:前面的变量不能使用后面的变量
TARGET := test
TARGET1 := test-bak

CC := gcc

#############################

.PHONY:all
all: $(TARGET) $(TARGET1)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# 自动推导
main.o: print.h 

print.o: print.c print.h
	$(CC) -c -o print.o print.c

$(TARGET1) : 
	$(CC) -o $(TARGET1) main-bak.c print.c


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
	rm -rf $(TARGET) $(OBJS) $(TARGET1) bin/
