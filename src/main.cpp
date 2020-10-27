#include "module.h"

#include <iostream>

int main() {
	std::cout << "Decision a * x = b(mod m)\n";

	long long a, b, m;

	std::cout << "a = ";
	std::cin >> a;
	
	std::cout << "b = ";
	std::cin >> b;

	std::cout << "m = ";
	std::cin >> m;

	std::cout << "First decision:\n" << decision(a, b, m, 1);
	std::cout << "Second decision:\n" << decision(a, b, m, 2);
	std::cout << "Third decision:\n" << decision(a, b, m, 3);
	return 0;
}