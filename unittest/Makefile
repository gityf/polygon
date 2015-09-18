include ../Makefile.comm
PROJECT = unittest

SRCS  = .
SRCS += ..

LIB  = -lstdc++ -lpthread -lm

INC  = -I.
INC += -I..

CPP_SRCS = $(foreach d,$(SRCS),$(wildcard $(d)/*.cpp))
OBJS = $(patsubst %.cpp, %.o, $(CPP_SRCS))

all : $(PROJECT)

$(PROJECT) : $(OBJS) $(MODULE)
	$(CC) -o $@ $(OBJS) $(LIB)
	@echo ""
	@echo "+--------------------------------------------+"
	@echo "|      Finish compilation unittest           |"
	@echo "+--------------------------------------------+"
	@echo "|   copyright(c)Wang Yaofu  voipman@qq.com   |"
	@echo "+--------------------------------------------+"

clean:
	rm -rf *.o *.a unittest

install :
	test -d ../test || mkdir -p ../test
	cp unittest ../test
