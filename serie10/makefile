COMPILER = g++
FLAGS = -std=c++11

triangle: triangle.o triangle_main.cpp
	${COMPILER} ${FLAGS} triangle_main.cpp triangle.o -o triangle
	
triangle.o: triangle.cpp
	${COMPILER} ${FLAGS} -c triangle.cpp 

ellipse: ellipse.o ellipse_main.cpp
	${COMPILER} ${FLAGS} ellipse_main.cpp ellipse.o -o ellipse

ellipse.o: ellipse.cpp
	${COMPILER} ${FLAGS} -c ellipse.cpp

palindrome: palindrome.cpp
	${COMPILER} ${FLAGS} palindrome.cpp -o palindrome

university: university.o university_main.cpp
	${COMPILER} ${FLAGS} university_main.cpp university.o -o university

university.o: university.cpp
	${COMPILER} ${FLAGS} -c university.cpp
	
name: name.o name_main.cpp
	${COMPILER} ${FLAGS} name_main.cpp name.o -o name

name.o: name.cpp
	${COMPILER} ${FLAGS} -c name.cpp
	
kunde: kunde.o kunde_main.cpp
	${COMPILER} ${FLAGS} kunde_main.cpp kunde.o -o kunde

kunde.o: kunde.cpp
	${COMPILER} ${FLAGS} -c kunde.cpp

roman: roman.cpp
	${COMPILER} ${FLAGS} roman.cpp -o roman
	
test: test.cpp
	${COMPILER} ${FLAGS} test.cpp -o test
	
clean:
	rm -f triangle*.o triangle.exe* triangle
	rm -f ellipse*.o ellipse.exe* ellipse
	rm -f palindrome.exe* palindrome
	rm -f university*.o university.exe* university
	rm -f name*.o name.exe* name
	rm -f kunde*.o kunde.exe* kunde
	rm -f roman.exe* roman
	rm -f test.exe* test