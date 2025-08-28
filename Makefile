SHELL=C:/Windows/System32/cmd.exe

SRC_DIR=src
OBJ_DIR=build
HDR_DIR=include

OBJECTS_LIST=square_equations.o Input.o IsZero.o NRoots.o Printer.o Solver.o Tester.o
OBJECTS=$(addprefix $(OBJ_DIR)/,$(OBJECTS_LIST))

all: main

main: $(OBJECTS)
	g++ $(OBJECTS) -o main

square_equations.o: $(SRC_DIR)square_equations.cpp
	g++ -c $(SRC_DIR)square_equations.cpp

Input.o: $(SRC_DIR)Input.cpp $(HDR_DIR)Input.hpp
	g++ -c $(SRC_DIR)Input.cpp

NRoots.o: $(SRC_DIR)NRoots.cpp $(HDR_DIR)NRoots.hpp
	g++ -c $(SRC_DIR)NRoots.cpp

Printer.o: $(SRC_DIR)Printer.cpp $(HDR_DIR)Input.hpp
	g++ -c $(SRC_DIR)Printer.cpp

Solver.o: $(SRC_DIR)Solver.cpp $(HDR_DIR)Solver.hpp
	g++ -c $(SRC_DIR)Solver.cpp

Tester.o: $(SRC_DIR)Tester.cpp $(HDR_DIR)Tester.hpp
	g++ -c $(SRC_DIR)Tester.cpp

clean:
	rm -rf *.o *.exe
