CXXFLAGS=
CXXFLAGS+=-Wall -Wextra -Werror
# VPATH=Task2_1

all: main

main: main.o
	g++ -g -o main main.o 

main.o: main.cpp connect_four.h human_player.h playfield.h gamelogic.h dominik.h
	g++ -c -g main.cpp

# connect_four.o: connect_four.cpp connect_four.h playfield.h
# 	g++ -c -g connect_four.cpp

# fraction.o: fraction.h
# 	g++ -c -g fraction.cpp

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $*.cpp
	@g++ -MM $(CXXFLAGS) -c $*.cpp >.depend/$*.d
