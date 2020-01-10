COMPILER = g++

polynomial: polynomial.o polynomial_main.cpp
	${COMPILER} polynomial_main.cpp polynomial.o -o polynomial
	
polynomial.o: polynomial.cpp
	${COMPILER} -c polynomial.cpp
	
clean:
	rm -f polynomial*.o polynomial.exe* polynomial
