#include "module.h"
#include "BigInt.h"

#include <iostream>
#include <exception>

int main() {
	std::cout << "Decision a * x = b(mod m)\n";

	BigInt a, b, m;

	std::cout << "a = ";
	std::cin >> a;
	
	std::cout << "b = ";
	std::cin >> b;

	std::cout << "m = ";
	std::cin >> m;

	std::cout << "Ways of solving the problem:\n";
	std::cout << "0 : EULER\n";
	std::cout << "1 : DIOPHANTINE\n";
	std::cout << "2 : BRUTE_FORCE_1\n";
	std::cout << "3 : BRUTE_FORCE_2\n";
	std::cout << "4 : FRACTIONS\n";

	size_t elem;
	std::cout << "Input solution number: ";
	try {
		if (!(std::cin >> elem) || elem > 4) throw std::exception();

		DecisionClass dc = static_cast<DecisionClass>(elem);
		std::cout << dc << " decision:\n" << decision(a, b, m, dc);
	}
	catch (const std::exception& err) {
		std::cout << "Wrong number";
	}
	return 0;
}