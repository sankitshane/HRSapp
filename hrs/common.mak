#It's a project root. Enter the directory path where "hrs" lies. DO NOT INCLUDE hrs.
PROJECT_ROOT =

CC = g++

AR = ar

CFLAGS = -Wall -g -O2 $(INCLUDE_PATH) -DALOGGER #-DWIN32

COMPILE = $(CC) $(CFLAGS) -c

OBJFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

