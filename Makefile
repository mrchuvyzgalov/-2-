Warnings = -Wall -Wextra -Werror

all: module

module: obj/main.o 
	g++ -std=c++17 $(Warnings) obj/main.o -o module

obj/main.o: src/main.cpp include/module.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/main.cpp -o obj/main.o

obj:
	mkdir obj

clean:
	rm -rf obj
	rm -rf module