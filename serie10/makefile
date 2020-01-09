COMPILER = g++

triangle: triangle.o triangle_main.cpp
	${COMPILER} triangle_main.cpp triangle.o -o triangle
	
triangle.o: triangle.cpp
	${COMPILER} -c triangle.cpp

ellipse: ellipse.o ellipse_main.cpp
	${COMPILER} ellipse_main.cpp ellipse.o -o ellipse

ellipse.o: ellipse.cpp
	${COMPILER} -c ellipse.cpp

palindrome: palindrome.cpp
	${COMPILER} palindrome.cpp -o palindrome

university: university.o university_main.cpp
	${COMPILER} university_main.cpp university.o -o university

university.o: university.cpp
	${COMPILER} -c university.cpp
	
name: name.o name_main.cpp
	${COMPILER} name_main.cpp name.o -o name

name.o: name.cpp
	${COMPILER} -c name.cpp
	
kunde: kunde.o kunde_main.cpp
	${COMPILER} kunde_main.cpp kunde.o -o kunde

kunde.o: kunde.cpp
	${COMPILER} -c kunde.cpp

roman: roman.cpp
	${COMPILER} roman.cpp -o roman
	
test: test.cpp
	${COMPILER} test.cpp -o test
	
clean:
	rm -f triangle*.o triangle.exe* triangle
	rm -f ellipse*.o ellipse.exe* ellipse
	rm -f palindrome.exe* palindrome
	rm -f university*.o university.exe* university
	rm -f name*.o name.exe* name
	rm -f kunde*.o kunde.exe* kunde
	rm -f roman.exe* roman
	rm -f test.exe* test