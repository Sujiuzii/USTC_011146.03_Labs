all: clean main

# CXX = g++
CXX = clang++
CXXFLAGS = -Wall -O3 -std=c++11

MAINCPP = main.cpp\
		  timer.cpp\
		  rw.cpp\
		  bfs.cpp


main: *.cpp
	$(CXX) $(CXXFLAGS) -o main $(MAINCPP)

clean:
	rm -f main

.PHONY: clean