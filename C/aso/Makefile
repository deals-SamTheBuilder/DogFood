VPATH ?= .:$VPATH

ALL_SRC = ./test-implicit.c ./welcome.c ./test-explicit.c
WEL_SRC := ./welcome.c
IMP_SRC := ./test-implicit.c 
EX_SRC := ./test-explicit.c 

ALL_OBJS := $(ALL_SRC:.c=.o)
WEL_OBJS := $(WEL_SRC:.c=.o)
IMP_OBJS := $(IMP_SRC:.c=.o)
EX_OBJS := $(EX_SRC:.c=.o)

WEL_TARGET := ./libwelcome.so
IMP_TARGET := ./test-implicit
EX_TARGET := ./test-explicit

CC := gcc
PLUS := g++ # 可以链接C++库
RM := -rm -rf
CFLAGS := -Wall -O2 -fPIC
IMP_LDFLAGS = -L. -lwelcome
EX_LDFLAGS = -ldl
LDSHFLAGS = -shared
CPPFLAGS = -I./

rely := $(ALL_SRC:.c=.d) # 生成.d文件
tmp := ./*.d.*

#############################

.PHONY: all implicit explicit clean 

all : $(WEL_TARGET)
$(WEL_TARGET): $(WEL_OBJS)
	$(PLUS) $(LDSHFLAGS) $^ -o $@

implicit : $(IMP_TARGET)
$(IMP_TARGET): $(IMP_OBJS)
	$(PLUS) $(IMP_LDFLAGS) $^ -o $@
	-export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH

explicit : $(EX_TARGET)
$(EX_TARGET): $(EX_OBJS)
	$(PLUS) $(EX_LDFLAGS) $^ -o $@
	
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
