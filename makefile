#makefile for final project

CXX = g++
CXXFLAGS = -Wall -g -std=c++0x

game: main.o Game.o gameFunctions.o Waiter.o Space.o Lobby.o Table.o Kitchen.o
	$(CXX) $(CXXFLAGS) main.o Game.o gameFunctions.o Waiter.o Space.o Lobby.o Table.o Kitchen.o -o game

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c

Game.o: Game.cpp
	$(CXX) $(CXXFLAGS) Game.cpp -c

gameFunctions.o: gameFunctions.cpp
	$(CXX) $(CXXFLAGS) gameFunctions.cpp -c

Waiter.o: Waiter.cpp
	$(CXX) $(CXXFLAGS) Waiter.cpp -c

Space.o: Space.cpp
	$(CXX) $(CXXFLAGS) Space.cpp -c

Lobby.o: Lobby.cpp
	$(CXX) $(CXXFLAGS) Lobby.cpp -c

Table.o: Table.cpp
	$(CXX) $(CXXFLAGS) Table.cpp -c

Kitchen.o: Kitchen.cpp
	$(CXX) $(CXXFLAGS) Kitchen.cpp -c

clean:
	rm *.o game


