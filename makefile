# makefile

all: elevator.cpp classrooms.cpp
	g++ elevator.cpp -o elevator
	g++ classrooms.cpp -o classrooms
clean:
	/bin/rm -f elevator classrooms
