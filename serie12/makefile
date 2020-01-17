COMPILER = g++
FLAGS = -std=c++11

fraction: fraction_main.cpp fraction.o fractionvector.o
	${COMPILER} fraction_main.cpp fraction.o fractionvector.o -o fraction
	
fraction.o: fraction.cpp
	${COMPILER} -c fraction.cpp
	
fractionvector.o: fractionvector.cpp
	${COMPILER} -c fractionvector.cpp

clean:
	rm -f fraction*.o fraction.exe* fraction