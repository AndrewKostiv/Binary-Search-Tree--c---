all: main

main: build/main.o build/BSTree.o
	g++ build/main.o build/BSTree.o -o main.exe

build/main.o: main.cpp BSTree/BSTree.h
	g++ -c main.cpp -o build/main.o

build/BSTree.o: BSTree/BSTree.cpp BSTree/BSTree.h
	g++ -c BSTree/BSTree.cpp -o build/BSTree.o

clean:
	rm -rf build/*.o *.o main.exe
