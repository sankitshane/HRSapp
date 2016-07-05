# Automated Makefile
include ../../../common.mak

OUTPUT_LIB = $(PROJECT_ROOT)/hrs/libs/libhrs.a

INCLUDE_PATH = -I$(PROJECT_ROOT)/hrs/include/

all: $(OUTPUT_LIB)

$(OUTPUT_LIB): $(OBJFILES)
	$(AR) -rc $(OUTPUT_LIB) $(OBJFILES)



%.o: %.cpp
	$(COMPILE) -o $@ $<

clean:
	rm -rf *.o *.a *~
