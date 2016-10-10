# 当前目录找不到依赖/目标文件时,去指定路径查找
VPATH ?= ~/Desktop/DogFood/make/:.
#vpath %.c %.h %.o ~/Desktop/DogFood/make/:.

SRC := ./main.c ./print.c
HELLO_SRC := ./print.c
OBJS := ./main.o ./print.o # 加了:前面的变量不能使用后面的变量
HELLO_OBJS := ./print.o
HELLO_TARGET := ./libhello.so
TARGET := test

CC := gcc
PLUS := g++
RM := -rm -rf # -表示命令出错.继续执行,忽略错误.
CPPFLAGS := -I ./# C预处理参数,一般设置I
CFLAGS := -Wall -O2 -m64 -D_GNU_SOURCE -fPIC # 编译器参数,C使用
#override CFLAGS += $(patsubst %,-I%,$(subst :, ,$(VPATH))) # 设置头文件搜索路径(-I)
CXXFLAGS := # C++使用
LDFLAGS :=  -L. -lhello # 链接器参数,如ld
LDSHFLAGS := -shared # 动态库编译参数

autoGenerate := yes # 是否自动生成依赖
rely := $(SRC:.c=.d) # 生成.d文件

####################
# $? ：比目标的修改时间更晚的那些依赖模块表。
# $@ ：当前目标的全路径名。可用于用户定义的目标名的相关行中。
# $< ：比给定的目标文件时间标记更新的依赖文件名。
# $^ : 所有依赖文件(去除重复,$+不去除)
# D/F :目录/文件 ,如$(<D)
# $* ：去掉后缀的当前目标名。例如，若当前目标是pro.o，则$*表示pro。
####################

.PHONY: all so

all: $(TARGET) # 默认只更新第一个目标,若有all,则可以指定多个目标

$(TARGET): $(OBJS)
	$(PLUS) $(CFLAGS) $^ -o $@

so : $(HELLO_TARGET)

$(HELLO_TARGET): $(HELLO_OBJS)
	$(PLUS) $(LDSHFLAGS) $^ -o $@

# 命令包
define generate-objs
	$(CC) -c $(CFLAGS) $< -o $@
endef

###  判断变量类型
#ifdef generate-objs
#ifeq ($(origin generate-objs),file)
#	echo "yes"
#else
#	echo "no"
#endif
#endif

# 判断是否自动生成依赖
ifeq ($(autoGenerate),no)
# 不自动生成依赖
## 隐含规则,不用写出来
#main.o: main.c print.h
#	$(CC) -c $(CFLAGS) $< -o $@
#
#print.o: print.c print.h
#	$(CC) -c $(CFLAGS) $< -o $@

else
# 自动生成依赖
%.d: %.c
	@set -e; rm -f $@ &> /dev/null; # 设置错误检查,若下面有语句执行错误则直接退出, 删除旧的.d文件\
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; # 生成依赖文件 \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; # 替换临时文件 \
	rm -f $@.$$$$ &> /dev/null # 删除临时文件

# 替换
-include $(rely)

endif

#################
# 显示指明伪目标,避免和文件重名,伪目标只是一个标签,不是一个文件.
.PHONY: hello install print tar dist TAGS check test
define hi
	@echo $(tips) # @不显示命令,只执行命令
endef

# 参数不是clean时才include
ifneq ( $(MAKECMDGOALS),clean)
-include hi.mk
endif

################
hello:
	$(hi)

install:

#######################
.PHONY: cleantar clean cleanobj cleangen cleanso
# 伪目标同样也可成为依赖
clean: cleantar cleanobj cleangen cleanso

cleantar:
	$(RM) $(TARGET)

cleanobj:
	$(RM) $(OBJS)

cleangen:
	$(RM) $(rely)

cleanso:
	$(RM) $(HELLO_TARGET)
