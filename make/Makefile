# 当前目录找不到依赖/目标文件时,去指定路径查找
VPATH ?= ~/Desktop/DogFood/make/:.
#vpath %.c %.h %.o ~/Desktop/DogFood/make/:.

SRC := ./main.c ./print.c
OBJS := main.o print.o # 加了:前面的变量不能使用后面的变量
TARGET := test

CC := gcc
RM := -rm -rf # -表示命令出错.继续执行,忽略错误.
CFLAGS := -Wall -O2 -I./ # 编译器参数,C使用
CXXFLAGS := # C++使用
LDFLAGS :=  # 链接器参数
LDSHFLAGS := -fPIC -shared # 动态库编译参数

####################
# $< : 第一个依赖文件
# $^ : 所有依赖文件
# $@ : 所有目标集合
####################

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# 命令包
define generate-objs
	$(CC) -c $(CFLAGS) $< -o $@
endef

#main.o: main.c print.h
#	$(generate-objs)
#print.o: print.c print.h
#	$(generate-objs)

# 自动生成依赖
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $< > $@.$$$$; \ # 生成依赖文件
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \ # 替换临时文件
	rm -f $@.$$$$ # 删除临时文件

include $(SRC:.c=.d) # 替换

#################
# 显示指明伪目标,避免和文件重名,伪目标只是一个标签,不是一个文件.
.PHONY: hello install
define hi
	@echo $(tips) # @不显示命令,只执行命令
endef

# include
-include hi.mk

################
hello:
	$(hi)

install:

#######################
.PHONY: cleantar cleanall cleanobj
# 伪目标同样也可成为依赖
cleanall: cleantar cleanobj
	$(RM) $(OBJS) $(TARGET)

cleantar:
	$(RM) $(TARGET)

cleanobj:
	$(RM) $(OBJS)
