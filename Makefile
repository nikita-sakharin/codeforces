CXX=g++
RM=rm -frd
CXXFLAGS=-fexceptions -m64 -pedantic-errors -std=c++20 -Wall -Wcast-qual \
    -Wcast-align -Wdouble-promotion -Weffc++ -Werror -Wextra -Wfatal-errors \
    -Wfloat-equal -Winit-self -Winline -Wmain -Wmissing-declarations \
    -Wmissing-include-dirs -Wnon-virtual-dtor -Wnull-dereference -Wpadded \
    -Wpedantic -Wredundant-decls -Wshadow -Wswitch-default -Wswitch-enum \
    -Wundef -Wuninitialized -Wunreachable-code -Wunused-const-variable=2 \
    -Wzero-as-null-pointer-constant
LDFLAGS=-m64
LDLIBS=-lm
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

debug: CXXFLAGS+=-Og -g
debug: all
release: CXXFLAGS+=-DNDEBUG -O3 -flto -s
release: LDFLAGS+=-O3 -flto -s
release: all

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
