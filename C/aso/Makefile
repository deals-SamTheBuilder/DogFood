VPATH ?= .:$VPATH

ALL_SRC = ./test.c ./welcome.c
WEL_SRC := ./welcome.c

ALL_OBJS := $(ALL_SRC:.c=.o)
WEL_OBJS := $(WEL_SRC:.c=.o)

TARGET := ./test
WEL_TARGET := ./libwelcome.so

CC := gcc
PLUS := g++ # 可以链接C++库
RM := -rm -rf
CFLAGS := -Wall -O2 -fPIC
LDFLAGS = -L. -lwelcome
LDSHFLAGS = -shared
CPPFLAGS = -I./

rely := $(ALL_SRC:.c=.d) # 生成.d文件
tmp := ./*.d.*

#############################

.PHONY: all clean cleanall 

all : $(WEL_TARGET)
$(WEL_TARGET): $(WEL_OBJS)
	$(PLUS) $(LDSHFLAGS) $(CPPFLAGS) $^ -o $@

# 自动生成依赖
$(rely): $(ALL_SRC)
	@set -e; rm -f $@ &> /dev/null; # 设置错误检查,若下面有语句执行错误则直接退出, 删除旧的.d文件\
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; # 生成依赖文件 \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; # 替换临时文件 \
	rm -f $@.$$$$ &> /dev/null # 删除临时文件

# 替换
-include $(rely)

clean:
	$(RM) $(rely) $(tmp) $(ALL_OBJS)
