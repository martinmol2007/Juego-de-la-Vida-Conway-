CXX = g++
CXXFLAGS = -Wall -Wextra

run: main.exe
	./main.exe

main.exe: main.cc src/game.cc
	$(CXX) $(CXXFLAGS) main.cc src/game.cc -o main.exe

.PHONY: run 
