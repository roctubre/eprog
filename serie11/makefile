COMPILER = g++
FLAGS = -std=c++11

polynomial: polynomial.o polynomial_main.cpp
	${COMPILER} ${FLAGS} polynomial_main.cpp polynomial.o -o polynomial
	
polynomial.o: polynomial.cpp
	${COMPILER} ${FLAGS} -c polynomial.cpp
	
clean:
	rm -f polynomial*.o polynomial.exe* polynomial
