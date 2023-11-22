all: main

main: *.cpp
	g++ main.cpp huffman.cpp -o main

test: *.cpp
	g++ huffmantest.cpp huffman.cpp -o test

clean:
	rm -f main test *.txt

cleantest:
	rm -f test
