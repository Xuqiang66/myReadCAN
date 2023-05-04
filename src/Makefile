# readcan
# $^ 依赖 不重复
# %@ 目标
# @ 不显示命令执行
TARGET=readcan
CFLAGS=-I/home/nvidia/myobject/myReadCAN/src
#LIBS=-L/home/nvidia/myfile/mymd5/lib
LIBS= -lsocketcan
OBJS=readcan.o im1_a_evb_v1_0_0_211018.o
$(TARGET):$(OBJS)
	@echo "begin build $(TARGET)"
	$(CXX) $^ $(CFLAGS) -o $@ $(LIBS)
	@echo "$(TARGET) build success!"

clean:
	$(RM) $(OBJS) $(TARGET)
.PHONY: clean *clean
