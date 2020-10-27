#include "module.h"

#include <cmath>
#include <iostream>



Leftovers::Leftovers() : leftovers({}) {}

Leftovers::Leftovers(const std::vector<long long>& newLeftovers) : leftovers(newLeftovers) { }

std::vector<long long> Leftovers::getLeftovers() const { return leftovers; }



Module::Module() : module(0) { }

Module::Module(const long long& newModule) : module(newModule) { };

long long Module::getModule() const { return module; }



Deductions::Deductions() : leftovers(Leftovers()), module(Module()) { };

Deductions::Deductions(const Leftovers& newLeftovers, const Module& newModule) : leftovers(newLeftovers), module(newModule) { }

std::ostream& operator <<(std::ostream& out, const Deductions& outDeductions) {
	std::vector<long long> leftovers = outDeductions.leftovers.getLeftovers();
	long long module = outDeductions.module.getModule();

	if (leftovers.size() == 0) out << "no decisions\n";

	for (auto curr : leftovers) { 
		out << "x = " << curr << " + " << module << " * k, k is integer\n";
	}

	return out;
}



long long mFastPow(const long long& a, const long long& n, const long long& mod) {
	if (n == 0) return 1;
	if (n % 2 == 1) return ((a % mod) * mFastPow(a, n - 1, mod)) % mod;

	long long tmp = mFastPow(a, n / 2, mod);
	return (tmp * tmp) % mod;
}

long long mSum(const long long& a, const long long& b, const long long& mod) {
	return ((a % mod) + (b % mod)) % mod;
}

long long mDif(const long long& a, const long long& b, const long long& mod) {
	return (mod + (a % mod) - (b % mod)) % mod;
}

long long mMul(const long long& a, const long long& b, const long long& mod) {
	return ((a % mod) * (b % mod)) % mod;
}

long long gcd(const long long& a, const long long& b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long extgcd(const long long& a, const long long& b, long long& x, long long& y) {
	if (a < b) return extgcd(b, a, y, x);
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long x1, y1;
	long long d = extgcd(b, a % b, x1, y1);
	y = x1 - (a / b) * y1;
	x = y1;
	return d;
}

long long EulerFunction(const long long& number) {
	long long tmpNumber = number;

	std::vector<long long> arr;

	long long tmpSimple = 2;
	while (tmpNumber > 1) {
		bool res = false;
		while (tmpNumber % tmpSimple == 0) {
			if (!res) {
				arr.push_back(tmpSimple);
				res = true;
			}
			tmpNumber /= tmpSimple;
		}
		tmpSimple++;
	}

	long long mulInArr1 = 1;
	long long mulInArr2 = 1;

	for (const auto& curr : arr) {
		mulInArr1 *= curr;
		mulInArr2 *= curr - 1;
	}

	return (number * mulInArr2) / mulInArr1;
}

Deductions decision(const long long& a, const long long& b, const long long& mod, const int numbOfDecision) {
	long long gcd_a_mod = gcd(a, mod);

	if (b % gcd_a_mod != 0) return Deductions();

	long long a1 = a / gcd_a_mod;
	long long b1 = b / gcd_a_mod;
	long long mod1 = mod / gcd_a_mod;

	long long x0 = 0;

	if (numbOfDecision == 1) {
		x0 = mMul(mFastPow(a1, mDif(EulerFunction(mod1), 1, mod1), mod1), b1, mod1);
	}
	else if (numbOfDecision == 2) {
		long long y0;
		extgcd(a1, mod1, x0, y0);

		x0 *= b1;
		if (x0 < 0) x0 += mod1 * std::ceil(-1.0 * x0 / mod1);
		if (x0 >= mod1) x0 %= mod1;
	}
	else if (numbOfDecision == 3) {
		while ((a1 * x0) % mod1 != (b1 % mod1)) x0++;
	}

	std::vector<long long> leftovers(gcd_a_mod);
	for (auto& curr : leftovers) {
		curr = x0;
		x0 += mod1;
	}

	return Deductions(Leftovers(leftovers), Module(mod));
}