all: direct indirect

# CXX = g++
CXX = clang++
CXXFLAGS = -Wall -O3 -std=c++11

DIRECTEDCPP = twitter.cpp\
		  timer.cpp\
		  rw.cpp\
		  bfs.cpp

INDIRECTEDCPP = indirect.cpp\
		  timer.cpp\
		  rw.cpp\
		  bfs.cpp

direct: $(DIRECTEDCPP)
	$(CXX) $(CXXFLAGS) -o direct $(DIRECTEDCPP)

indirect: $(INDIRECTEDCPP)
	$(CXX) $(CXXFLAGS) -o indirect $(INDIRECTEDCPP)

clean:
	rm -f direct indirect 

.PHONY: clean
