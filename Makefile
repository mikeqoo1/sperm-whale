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
DEFAULT_FILE=$(SRC)animal.cpp

MAIN_OUTPUT=animal.out

.PHONY: clean main debug all

main:$(DEFAULT_FILE)
	$(CC) $(FLAG) $(INC) -o $(MAIN_OUTPUT) $(MAIN_FILE) $(DEFAULT_FILE)

all:main test debug db

clean:
	rm *.out