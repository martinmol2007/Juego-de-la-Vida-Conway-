CXX = g++
CXXFLAGS = -Wall -Wextra

run: main.exe
	./main.exe

main.exe: main.cc src/game.cc
	$(CXX) $(CXXFLAGS) main.cc src/game.cc -o main.exe

clean: main.exe	
	rm -f main.exe

.PHONY: run clean
