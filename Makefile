CXXFLAGS = -Wall -Werror -pedantic -std=c++11
CPPSOURCES = $(shell find -name '*.cpp')
CPPOBJS = $(patsubst %.cpp,%.o,$(CPPSOURCES))
PROG = enigma

.PHONY : all clean

all: $(PROG)

$(PROG): $(CPPOBJS)
	$(CXX) $(CPPOBJS) -o $@

clean:
	rm -f *~ $(shell find -name '*.gch') $(shell find -name '*.o') $(PROG)
