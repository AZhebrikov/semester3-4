prog: prog.o fun.o fun1.o fun2.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog  prog.o fun.o fun1.o fun2.o
fun1.o: fun1.cpp fun.h  Makefile
				wg++ -c fun1.cpp
fun2.o: fun2.cpp fun.h  Makefile
				wg++ -c fun2.cpp
fun.o: fun.cpp fun.h  Makefile
				wg++ -c fun.cpp
prog.o: prog.cpp fun.h  Makefile
				wg++ -c prog.cpp
