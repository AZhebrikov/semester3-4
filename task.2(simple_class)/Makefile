prog: prog.o fun.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog prog.o fun.o
fun.o: fun.cpp fun_CRat.h fun_CRatVector.h Makefile
				wg++ -c fun.cpp
prog.o: prog.cpp fun_CRat.h fun_CRatVector.h Makefile
				wg++ -c prog.cpp

