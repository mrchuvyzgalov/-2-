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

	std::cout << "EULER decision:\n" << decision(a, b, m, DecisionClass::EULER);
	std::cout << "DIOPHANTINE decision:\n" << decision(a, b, m, DecisionClass::DIOPHANTINE);
	std::cout << "BRUTE_FORCE_1 decision:\n" << decision(a, b, m, DecisionClass::BRUTE_FORCE_1);
	std::cout << "BRUTE_FORCE_2 decision:\n" << decision(a, b, m, DecisionClass::BRUTE_FORCE_2);
	std::cout << "FRACTIONS decision:\n" << decision(a, b, m, DecisionClass::FRACTIONS);
	return 0;
}