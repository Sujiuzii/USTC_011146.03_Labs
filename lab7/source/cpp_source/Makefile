all: main

CC = g++
CFLAGS = -Wall -O3 --std=c++11

main: *.cpp
	$(CC) $(FLAGS) main.cpp optimalscheduling.cpp rw.cpp timer.cpp -o main

test:
	$(CC) $(FLAGS) test1.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test1
	$(CC) $(FLAGS) test2.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test2
	$(CC) $(FLAGS) test3.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test3
	./test1
	./test2
	./test3
	rm -f test1 test2 test3

test1: *.cpp
	$(CC) $(FLAGS) test1.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test1

test2: *.cpp
	$(CC) $(FLAGS) test2.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test2

test3: *.cpp
	$(CC) $(FLAGS) test3.cpp optimalscheduling.cpp rw.cpp timer.cpp -o test3

clean:
	rm -f main test1 test2 test3

cleantest:
	rm -f test1 test2 test3

.PHONY: all clean test cleantest
