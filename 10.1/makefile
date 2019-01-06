CC := gcc
LD := ld
RM := rm -rf

TARGET := mymain.out
SRC    := $(TARGET:.out=.c)
OBJ    := $(TARGET:.out=.o)
LDS    := $(TARGET:.out=.lds)

.PHONY : rebuild clean all

$(TARGET) : $(OBJ)
	# -T用于指定从后的链接文件读取链接脚本信息
	# -static 静态链接的方式来产生最终程序，而不是默认的动态链接方式。
	$(LD) -static -T $(LDS) -o $@ $<   
	@echo "Target File ==> $@"
    
$(OBJ) : $(SRC) $(LDS)
	# $< 第一个依赖， $^ 当前规则中的所有依赖
	# -fno-builtin GCC提供了很多内置函数（Built-in Function），它会把一些常用的C库函数替换成编译器的内置函数，以达到优化的目的。-fno-builtin参数用于关闭GCC内置函数的功能
	$(CC) -fno-builtin -o $@ -c $<     

rebuild : clean all

all : $(TARGET)

clean : 
	$(RM) $(TARGET) $(OBJ)