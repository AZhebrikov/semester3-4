prog: prog.o fun.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog prog.o fun.o
fun.o: fun.cpp fun.h  Makefile
				wg++ -c fun.cpp
prog.o: prog.cpp fun.h Makefile
				wg++ -c prog.cpp

