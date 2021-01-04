#include "BigInt.h"
#include "module.h"
#include "modulo_operations.h"

#include <iostream>
#include <random>

BigInt GenerateSimple(size_t seed);
bool IsSimple(const BigInt& bi);

int main() {
	size_t seed = 11;
	BigInt p = GenerateSimple(seed);
	BigInt q;
	do {
		q = GenerateSimple(seed += 17);
	} while (p == q);

	BigInt n = p * q;
	BigInt fn = (p - BigInt(1)) * (q - BigInt(1));

	std::random_device rd;
	std::mt19937 mersenne(rd());

	BigInt e = BigInt(65537) + BigInt(mersenne());
	while (gcd(fn, e) != BigInt(1)) {
		e += BigInt(1);
	}

	std::cout << "Public key: {" << e << ", " << n << "}\n";

	BigInt d = decision(e, BigInt(1), fn, DecisionClass::DIOPHANTINE).get_leftover();

	std::cout << "Private key: {" << d << ", " << n << "}\n";
	return 0;
}

BigInt GenerateSimple(size_t seed) {
	std::random_device rd;
	std::mt19937 mersenne(rd());

	BigInt numb1(mersenne());
	numb1 += BigInt("1234567891") * BigInt(seed) + BigInt(mersenne()) + BigInt(mersenne());

	while (!IsSimple(numb1)) {
		numb1 += BigInt(1);
	}

	return numb1;
}

bool IsSimple(const BigInt& bi) {
	for (BigInt tmp(2); tmp * tmp <= bi; tmp += BigInt(1)) {
		if (bi % tmp == BigInt(0)) return false;
	}
	return true;
}