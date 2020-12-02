Warnings = -Wall -Wextra -Werror

all: module test

module: obj/main.o 
	g++ -std=c++17 $(Warnings) obj/main.o -o module

obj/main.o: src/main.cpp include/module.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/main.cpp -o obj/main.o

test: obj/test.o obj/test_modulo_operations.o
	g++ -std=c++17 $(Warnings) obj/test.o obj/test_modulo_operations.o -o test

obj/test.o: src/test.cpp include/test_modulo_operations.h include/UnitTestFramework.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/test.cpp -o obj/test.o

obj/test_modulo_operations.o: src/test_modulo_operations.cpp include/test_modulo_operations.h include/modulo_operations.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/test_modulo_operations.cpp -o obj/test_modulo_operations.o

obj:
	mkdir obj

clean:
	rm -rf obj
	rm -rf module
	rm -rf test