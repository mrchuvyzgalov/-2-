Warnings = -Wall -Wextra -Werror

all: module test

module: obj/main.o 
	g++ -std=c++17 $(Warnings) obj/main.o -o module

obj/main.o: src/main.cpp include/module.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/main.cpp -o obj/main.o

test: obj/test.o obj/test_modulo_operations.o obj/test_fraction.o obj/test_decision.o obj/test_bigint.o obj/BigInt.o
	g++ -std=c++17 $(Warnings) obj/test.o obj/test_modulo_operations.o  obj/test_fraction.o obj/test_decision.o obj/test_bigint.o obj/BigInt.o -o test

obj/test.o: src/test.cpp include/test_modulo_operations.h include/test_runner.h include/test_fraction.h include/test_decision.h include/test_bigint.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/test.cpp -o obj/test.o

obj/test_modulo_operations.o: src/test_modulo_operations.cpp include/test_modulo_operations.h include/modulo_operations.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/test_modulo_operations.cpp -o obj/test_modulo_operations.o

obj/test_fraction.o: src/test_fraction.cpp include/test_fraction.h include/Fraction.h include/test_runner.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/test_fraction.cpp -o obj/test_fraction.o

obj/test_decision.o: src/test_decision.cpp include/test_decision.h include/test_runner.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/test_decision.cpp -o obj/test_decision.o

obj/test_bigint.o: src/test_bigint.cpp include/test_bigint.h include/test_runner.h include/BigInt.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/test_bigint.cpp -o obj/test_bigint.o

obj/BigInt.o: src/BigInt.cpp include/BigInt.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/BigInt.cpp -o obj/BigInt.o

obj:
	mkdir obj

clean:
	rm -rf obj
	rm -rf module
	rm -rf test