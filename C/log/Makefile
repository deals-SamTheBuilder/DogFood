VPATH ?= .:$VPATH

SRC = ./test.c
ALL_SRC = ./test.c ./log.c
LOG_SRC := ./log.c

OBJS := $(SRC:.c=.o)
ALL_OBJS := $(ALL_SRC:.c=.o)
LOG_OBJS := $(LOG_SRC:.c=.o)

TARGET := ./test
LOG_TARGET := ./liblog.so

CC := gcc
RM := -rm -rf
CFLAGS := -Wall -O2
LDFLAGS = -L -llog
LDSHFLAGS = -fPIC -shared
CPPFLAGS = -I./

rely := $(ALL_SRC:.c=.d) # 生成.d文件
tmp := ./*.d.*

#############################

.PHONY: all so clean cleanall 

all : $(TARGET)
$(TARGET): $(ALL_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) $^ -o $@

so : $(LOG_TARGET)
$(LOG_TARGET): $(LOG_SRC)
	$(CC) $(LDSHFLAGS) $(CFLAGS) $(CPPFLAGS) $^ -o $@

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

cleanall:
	$(RM) $(LOG_TARGET) $(TARGET) $(rely) $(tmp)  $(ALL_OBJS)
