#pragma once

#include "modulo_operations.h"

#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>

template <class T>
class Deductions {
public:
	explicit Deductions(const std::vector<T>& newLeftovers, const T& newModule);

	std::vector<T> get_leftovers() const noexcept;
	T get_module() const noexcept;

	template <class U>
	friend std::ostream& operator <<(std::ostream& out, const Deductions<U>& outDeductions);

private:
	std::vector<T> leftovers;
	T module;
};

template <class T>
Deductions<T> decision(const T& a, const T& b, const T& mod, const int numbOfDecision);


template <class T>
Deductions<T>::Deductions(const std::vector<T>& newLeftovers, const T& newModule) : leftovers(newLeftovers), module(newModule) { }

template <class T>
std::vector<T> Deductions<T>::get_leftovers() const noexcept {
	return leftovers;
}

template <class T>
T Deductions<T>::get_module() const noexcept {
	return module;
}

template <class U>
std::ostream& operator <<(std::ostream& out, const Deductions<U>& outDeductions) {
	std::vector<U> leftovers = outDeductions.get_leftovers();
	U module = outDeductions.get_module();

	if (leftovers.size() == 0) out << "no decisions\n";

	for (auto curr : leftovers) { 
		out << "x = " << curr << " + " << module << " * k, k is integer\n";
	}

	return out;
}



template <class T>
Deductions<T> decision(const T& a, const T& b, const T& mod, const int numbOfDecision) {
	T gcd_a_mod = gcd(a, mod);

	if (b % gcd_a_mod != 0) return Deductions<T>(std::vector<T>{}, T(0));

	T a1 = a / gcd_a_mod;
	T b1 = b / gcd_a_mod;
	T mod1 = mod / gcd_a_mod;

	T x0 = 0;

	if (numbOfDecision == 1) {
		x0 = mMul<T>(mFastPow<T>(a1, mDif<T>(EulerFunction<T>(mod1), 1, mod1), mod1), b1, mod1);
	}
	else if (numbOfDecision == 2) {
		T y0;
		extgcd(a1, mod1, x0, y0);

		x0 *= b1;
		if (x0 < 0) x0 += mod1 * std::ceil(-1.0 * x0 / mod1);
		if (x0 >= mod1) x0 %= mod1;
	}
	else if (numbOfDecision == 3) {
		while ((a1 * x0) % mod1 != (b1 % mod1)) x0++;
	}

	std::vector<T> leftovers(gcd_a_mod);
	for (auto& curr : leftovers) {
		curr = x0;
		x0 += mod1;
	}

	return Deductions<T>(std::vector<T>(leftovers), T(mod));
}