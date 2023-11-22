all: main

main: *.cpp
	g++ main.cpp optimalscheduling.cpp rw.cpp timer.cpp -o main

test: test1 test2 test3 cleantest

test1: *.cpp
	g++ test1.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test1
	./test1

test2: *.cpp
	g++ test2.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test2
	./test2

test3: *.cpp
	g++ test3.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test3
	./test3

clean:
	rm -f main test1 test2 test3

cleantest:
	rm -f test1 test2 test3
