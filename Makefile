SHELL=C:/Windows/System32/cmd.exe

SRC_DIR=src
OBJ_DIR=build
HDR_DIR=include

OBJECTS_LIST=square_equations.o Input.o IsZero.o NRoots.o Printer.o Solver.o Tester.o
OBJECTS=$(addprefix $(OBJ_DIR)/,$(OBJECTS_LIST))

CXXFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main

main: $(OBJECTS)
	g++ $(OBJECTS) -o main

$(OBJ_DIR)/square_equations.o: $(SRC_DIR)/square_equations.cpp
	g++ $(CXXFLAGS) -c $(SRC_DIR)/square_equations.cpp -o $(OBJ_DIR)/square_equations.o

$(OBJ_DIR)/Input.o: $(SRC_DIR)/Input.cpp $(HDR_DIR)/Input.hpp
	g++ $(CXXFLAGS) -c $(SRC_DIR)/Input.cpp -o $(OBJ_DIR)/Input.o

$(OBJ_DIR)/NRoots.o: $(SRC_DIR)/NRoots.cpp $(HDR_DIR)/NRoots.hpp
	g++ $(CXXFLAGS) -c $(SRC_DIR)/NRoots.cpp -o $(OBJ_DIR)/NRoots.o

$(OBJ_DIR)/Printer.o: $(SRC_DIR)/Printer.cpp $(HDR_DIR)/Printer.hpp
	g++ $(CXXFLAGS) -c $(SRC_DIR)/Printer.cpp -o $(OBJ_DIR)/Printer.o

$(OBJ_DIR)/Solver.o: $(SRC_DIR)/Solver.cpp $(HDR_DIR)/Solver.hpp
	g++ $(CXXFLAGS) -c $(SRC_DIR)/Solver.cpp -o $(OBJ_DIR)/Solver.o

$(OBJ_DIR)/Tester.o: $(SRC_DIR)/Tester.cpp $(HDR_DIR)/Tester.hpp
	g++ $(CXXFLAGS) -c $(SRC_DIR)/Tester.cpp -o $(OBJ_DIR)/Tester.o

clean:
	rm -rf *.o *.exe
