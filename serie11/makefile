COMPILER = g++
FLAGS = -std=c++11

polynomial: polynomial.o polynomial_main.cpp
	${COMPILER} polynomial_main.cpp polynomial.o -o polynomial
	
polynomial.o: polynomial.cpp
	${COMPILER} -c polynomial.cpp
	
addpolynomials: polynomial.o addpolynomials.cpp
	${COMPILER} ${FLAGS} addpolynomials.cpp polynomial.o -o addpolynomials
	
prodpolynomials: polynomial.o prodpolynomials.cpp
	${COMPILER} ${FLAGS} prodpolynomials.cpp polynomial.o -o prodpolynomials
	
comparepolynomials: polynomial.o comparepolynomials.cpp
	${COMPILER} ${FLAGS} comparepolynomials.cpp polynomial.o -o comparepolynomials	

clean:
	rm -f polynomial*.o polynomial.exe* polynomial
	rm -f addpolynomials.exe* addpolynomials
	rm -f prodpolynomials.exe* prodpolynomials
	rm -f comparepolynomials.exe* comparepolynomials