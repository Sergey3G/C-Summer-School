all:
	main

main: square_equations.o Input.o IsZero.o NRoots.o Printer.o Solver.o Tester.o
	g++ square_equations.o Input.o IsZero.o NRoots.o Printer.o Solver.o Tester.o -o main

square_equations.o: square_equations.cpp
	g++ -c square_equations.cpp

Input.o: Input.cpp Input.hpp
	g++ -c Input.cpp

NRoots.o: NRoots.cpp NRoots.hpp
	g++ -c NRoots.cpp

Printer.o: Printer.cpp Input.hpp
	g++ -c Printer.cpp

Solver.o: Solver.cpp Solver.hpp
	g++ -c Solver.cpp

Tester.o: Tester.cpp Tester.hpp
	g++ -c Tester.cpp

clean:
	rm -rf *.o main
