COMPILER = g++
FLAGS = -std=c++11

fraction: fraction.o fraction_main.cpp
	${COMPILER} fraction_main.cpp fraction.o -o fraction
	
fraction.o: fraction.cpp
	${COMPILER} -c fraction.cpp

clean:
	rm -f fraction*.o fraction.exe* fraction