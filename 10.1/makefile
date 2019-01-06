CC := gcc
LD := ld
RM := rm -rf

TARGET := mymain.out
SRC    := $(TARGET:.out=.c)
OBJ    := $(TARGET:.out=.o)
LDS    := $(TARGET:.out=.lds)

.PHONY : rebuild clean all

$(TARGET) : $(OBJ)
	# -T����ָ���Ӻ�������ļ���ȡ���ӽű���Ϣ
	# -static ��̬���ӵķ�ʽ���������ճ��򣬶�����Ĭ�ϵĶ�̬���ӷ�ʽ��
	$(LD) -static -T $(LDS) -o $@ $<   
	@echo "Target File ==> $@"
    
$(OBJ) : $(SRC) $(LDS)
	# $< ��һ�������� $^ ��ǰ�����е���������
	# -fno-builtin GCC�ṩ�˺ܶ����ú�����Built-in Function���������һЩ���õ�C�⺯���滻�ɱ����������ú������Դﵽ�Ż���Ŀ�ġ�-fno-builtin�������ڹر�GCC���ú����Ĺ���
	$(CC) -fno-builtin -o $@ -c $<     

rebuild : clean all

all : $(TARGET)

clean : 
	$(RM) $(TARGET) $(OBJ)