CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11
CPPSOURCES = $(shell find -name '*.cpp')
CSOURCES = $(shell find -name '*.c')
CPPOBJS = $(CPPSOURCES: .cpp=.o)
COBJS = $(CSOURCES: .c=.o)
PROG = enigma

.PHONY : all clean

all: clean $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(COBJS) $(CPPOBJS) -o $@

clean:
	rm -f *~ $(shell find -name '*.gch') $(PROG)
