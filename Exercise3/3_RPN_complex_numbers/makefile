CXXFLAGS=
CXXFLAGS+=-Wall -Wextra -Werror
# VPATH=Task2_1

all: main

main: main.o pvector.o 
	g++ -g -o main main.o pvector.o

main.o: main.cpp fraction.h rpn.h pvector.h 
	g++ -c -g main.cpp


# fraction.o: fraction.h
# 	g++ -c -g fraction.cpp

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $*.cpp
	@g++ -MM $(CXXFLAGS) -c $*.cpp >.depend/$*.d
