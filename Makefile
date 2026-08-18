CXX = g++
CXXFLAGS = -Wall -Wextra

run: main.exe
	./main.exe

main.exe: main.cc src/game.cc include/game.hh
	$(CXX) $(CXXFLAGS) main.cc src/game.cc -o main.exe

clean:
	rm -f main.exe

.PHONY: run clean
