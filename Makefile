CC=g++
FLAG=-Wall -std=c++11 -pthread
INC=-I./inc/

# OSID := $(shell grep '^ID=' /etc/os-release | cut -f2- -d= | sed -e 's/\"//g')
# ifeq ($(OSID), ubuntu)
# LIB+=-lmariadb
# INC+=-I/usr/include/mariadb
# LIBDIR+=-L/usr/lib/x86_64-linux-gnu
# else
# ifeq ($(OSID), rocky)
# LIB+=-lmysqlclient
# LIBDIR+=-L/usr/include/mysql
# else
# ifeq ($(OSID), centos)
# LIB+=-lmysqlclient
# LIBDIR+=-L/usr/include/mysql
# endif # centos
# endif # rocky
# endif # ubuntu

DEBUG=-g
SRC=./src/

MAIN_FILE=$(SRC)main.cpp
DEFAULT_FILE=$(SRC)animal.cpp $(SRC)sea.cpp
DISASSEMBLER_FILE=disassembler/test.cpp

MAIN_OUTPUT=animal.out

.PHONY: clean main debug all

main:$(DEFAULT_FILE)
	$(CC) $(FLAG) $(INC) -o $(MAIN_OUTPUT) $(MAIN_FILE) $(DEFAULT_FILE)


#-c 只編譯不連結 -E 預處理 -S 只建立assemblely檔
debug:$(DISASSEMBLER_FILE)
	$(CC) -c -g $(DISASSEMBLER_FILE)
	$(CC) -E $(DISASSEMBLER_FILE) -o disassembler/test.i
	$(CC) -S $(DISASSEMBLER_FILE) -o disassembler/test.a
	$(CC) test.o -g -o disassembler/test.out
	objdump -j .text -l -C -S disassembler/test.out >> 逆向工程.txt

all:main debug

clean:
	rm *.out *.o
	rm disassembler/*.out disassembler/*.o disassembler/*.a disassembler/*.i