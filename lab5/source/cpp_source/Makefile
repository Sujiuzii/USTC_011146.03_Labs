all: main

main: main.cpp lcs.cpp
	g++ main.cpp lcs.cpp -o main

test: *.cpp
	g++ test.cpp lcs.cpp -o test1
	g++ test2.cpp lcs.cpp -o test2
	g++ test3.cpp lcs.cpp -o test3

clean:
	rm -f main test1 test2 test3

cleantest:
	rm -f test1 test2 test3
