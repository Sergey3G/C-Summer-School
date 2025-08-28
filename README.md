Quadratic Equation Solver in C
================================

A console application for solving quadratic equations of the form `ax² + bx + c = 0`. The program calculates equation roots, handles special cases, and includes testing functionality.

Features
========

- Solves standard quadratic equations
- Handles degenerate cases (linear equations)
- Built-in testing system
- Cross-platform compilation

Requirements
============

- C/C++ compiler (GCC, MinGW, Clang)
- Make utility
- Operating System: No matter

Building the Project
====================

1. Clone the repository:
```bash
git clone https://github.com/Sergey3G/C-Summer-School.git
cd C-Summer-School
```

1. Build the program using Makefile:
```bash
make
```

After successful compilation, an executable file `main.exe` (Windows) will be created.

Usage
=====

### Interactive Mode
Run the program and enter coefficients a, b, and c when prompted:

```bash
./main
Enter coefficients of quadratic equation ax^2 + bx + c = 0: 1 -3 2
Two roots: x1 = 2, x2 = 1
```

### Test Mode
To run tests:

```bash
./main --test
```

### Solving Mode
Pass coefficients as command line arguments:

```bash
./main --solve
Enter coefficients of quadratic equation ax^2 + bx + c = 0: 1 -3 2
Two roots: x1 = 2, x2 = 1
```

## Examples

```bash
# Standard quadratic equation
$ ./main --solve
Enter coefficients of quadratic equation ax^2 + bx + c = 0: 1 -3 2
Two roots: x1 = 2.000, x2 = 1.000

# Equation with single root
$ ./main --solve
Enter coefficients of quadratic equation ax^2 + bx + c = 0: 1 2 1
One root: x = -1

# Equation with no roots
$ ./main --solve
Enter coefficients of quadratic equation ax^2 + bx + c = 0: 1 2 5
No roots.

# Linear equation
$ ./main --solve
Enter coefficients of quadratic equation ax^2 + bx + c = 0: 0 2 4
One root: x = -2

# Degenerate equation
$ ./main --solve
Enter coefficients of quadratic equation ax^2 + bx + c = 0: 0 0 5
No roots

# Equation with zero coefficients
$ ./main --solve
Enter coefficients of quadratic equation ax^2 + bx + c = 0: 0 0 0
Infinite roots
```

Project Structure
=================

```
C-Summer-School/
├── src/
│   ├── square_equations.cpp  # Main program file
│   ├── Input.cpp             # Input processing module
│   ├── IsZero.cpp            # Check-on-equality-to-zero utility
│   ├── Printer.cpp           # Roots output utility
│   ├── Solver.cpp            # Equation solver
│   └── Tester.cpp            # Testing module
├── include/
│   ├── Input.hpp             # Input module header
│   ├── NRoots.hpp            # Contains enum of number-of-roots constants
│   ├── Solver.hpp            # Solver module header
│   ├── Tester.hpp            # Testing module header
│   ├── IsZero.hpp            # IsZero module header
|   ├── Colours.hpp           # Contains of colour codes constants
|   ├── Printer.hpp           # Printer module header
├── Makefile                  # Build configuration
└── README.md                 # This file
```

Build Commands
==============

The project uses Makefile for building. Available commands:

- `make` or `make all` - build the program
- `make clean` - remove compiled files


Author
======

Developed as part of Summer Programming School.
GitHub: [Sergey3G](https://github.com/Sergey3G)


