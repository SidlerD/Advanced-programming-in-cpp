CXXFLAGS=
CXXFLAGS+=-Wall -Wextra -Werror

all: main

main: main.o
	g++ -g -o main main.o 

main.o: main.cpp dumb_pointer.h smart_pointer.h
	g++ -c -g main.cpp

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $*.cpp
	@g++ -MM $(CXXFLAGS) -c $*.cpp >.depend/$*.d
