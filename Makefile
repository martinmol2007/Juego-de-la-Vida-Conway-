CXX = g++
CXXFLAGS = -Wall -Wextra

run: main
	./main

main: main.cc src/game.cc
	$(CXX) $(CXXFLAGS) main.cc src/game.cc -o main

clean: main
	rm -f main

.PHONY: run clean
