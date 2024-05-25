main: main.o fun1.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o main  main.o  fun1.o
prog4: prog4.o fun1.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog4  prog4.o  fun1.o
prog5: prog5.o fun1.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog5  prog5.o  fun1.o
prog3: prog3.o fun1.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog3  prog3.o  fun1.o
prog2: prog2.o fun1.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog2  prog2.o  fun1.o
prog1: prog1.o fun1.o Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog1  prog1.o  fun1.o
prog: prog.o  fun1.o  Makefile
				wg++ -std=c++11 -fno-elide-constructors -o prog  prog.o  fun1.o 
fun1.o: fun1.cpp fun.h  Makefile
				wg++ -c fun1.cpp
prog.o: prog.cpp fun.h  Makefile
				wg++ -c prog.cpp
prog1.o: prog1.cpp fun.h Makefile
				wg++ -c prog1.cpp 
prog2.o: prog2.cpp fun.h Makefile
				wg++ -c prog2.cpp 
prog3.o: prog3.cpp fun.h Makefile
				wg++ -c prog3.cpp 
prog4.o: prog4.cpp fun.h Makefile
				wg++ -c prog4.cpp 
main.o: main.cpp fun.h Makefile
				wg++ -c main.cpp 
prog5.o: prog5.cpp fun.h Makefile
				wg++ -c prog5.cpp 
