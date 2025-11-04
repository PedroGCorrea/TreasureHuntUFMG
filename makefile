all: compile link run

delete:
	del *.o

compile:
	g++ -c main.c src/*.c

link:
	g++ *.o -o main 

run:
	./main.exe
