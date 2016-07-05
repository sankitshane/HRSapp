# Automated Makefile

include ../common.mak 

OUTPUT_EXE = hrs.exe

####################################################################################

INCLUDE_PATH = -I $(PROJECT_ROOT)/hrs/include  #-I $(CPP_UNIT_INC)

LIB_PATH = -L $(PROJECT_ROOT)/hrs/libs #-L/cygdrive/c/cygwin/lib/w32api/  #-L $(CPP_UNIT_LIB)

LIBS = -lalogger -lhrs -ldbaccess -lodbc -lcurses

#####################################################################################
CC = g++

CFLAGS = -Wall -O2 $(INCLUDE_PATH) -DALOGGER #-DWIN32 -DCPPUNIT_TESTING 

COMPILE = $(CC) $(CFLAGS) -c

OBJFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))



all: $(OUTPUT_EXE)

$(OUTPUT_EXE): $(OBJFILES)
	$(CC) -o $(OUTPUT_EXE) $(OBJFILES) $(LIB_PATH) $(LIBS)



%.o: %.cpp
	$(COMPILE) -o $@ $<

clean:
	rm -rf *.o *.a *.exe *.log *~
