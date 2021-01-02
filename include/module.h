#pragma once

#include "modulo_operations.h"
#include "Fraction.h"

#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>

enum class DecisionClass { EULER, DIOPHANTINE, BRUTE_FORCE_1, BRUTE_FORCE_2, FRACTIONS };

std::ostream& operator <<(std::ostream& out, const DecisionClass& class_);

template <class T>
class Deductions {
public:
	Deductions(const T& newLeftover, const T& newStep, const T& newModule, bool decision);

	template <class U>
	friend std::ostream& operator <<(std::ostream& out, const Deductions<U>& outDeductions);

private:
	T firstLeftover;
	T step;
	T module;
	bool hasDecision;
};

template <class T>
Deductions<T> decision(T a, T b, const T& mod, const DecisionClass& classOfDecision);


template <class T>
Deductions<T>::Deductions(const T& newLeftover, const T& newStep, const T& newModule, bool decision) : firstLeftover(newLeftover), step(newStep), module(newModule), hasDecision(decision) { }

template <class U>
std::ostream& operator <<(std::ostream& out, const Deductions<U>& outDeductions) {
	if (!outDeductions.hasDecision) {
		out << "no decisions\n";
	}
	else {
		for (U curr = outDeductions.firstLeftover; curr < outDeductions.module; curr += outDeductions.step) {
			out << "x = " << curr << " + " << outDeductions.module << " * k, k is integer\n";
		}
	}

	return out;
}

template <class T>
Deductions<T> decision(T a, T b, const T& mod, const DecisionClass& classOfDecision) {
	if (a < T(0)) a += mod * ((T(-1) * a) / mod + T(1));
	if (b < T(0)) b += mod * ((T(-1) * b) / mod + T(1));

	T gcd_a_mod = gcd(a, mod);

	if (b % gcd_a_mod != T(0)) return Deductions<T>(T(0), T(0), mod, false);

	T a1 = a / gcd_a_mod;
	T b1 = b / gcd_a_mod;
	T mod1 = mod / gcd_a_mod;

	T x0 = T(0);

	if (classOfDecision == DecisionClass::EULER) { // Euler's theorem
		x0 = mMul<T>(mFastPow<T>(a1, mDif<T>(EulerFunction<T>(mod1), T(1), mod1), mod1), b1, mod1);
	}
	else if (classOfDecision == DecisionClass::DIOPHANTINE) { // Diophantine equation
		T y0;
		extgcd(a1, mod1, x0, y0);

		x0 *= b1;
		if (x0 < T(0)) x0 += mod1 * ((T(-1) * x0) / mod1 + T(1));
		if (x0 >= mod1) x0 %= mod1;
	}
	else if (classOfDecision == DecisionClass::BRUTE_FORCE_1) { // brute force 1
		while ((a1 * x0) % mod1 != (b1 % mod1)) x0 = x0 + T(1);
	}
	else if (classOfDecision == DecisionClass::BRUTE_FORCE_2) { // brute force 2
		T tmp = b1;
		while (tmp % a1 != T(0)) tmp += mod1;
		x0 = tmp / a1;
	}
	else if (classOfDecision == DecisionClass::FRACTIONS) { // fractions
		Fraction<T> fr(mod1, a1);

		std::vector<T> nums = fr.get_numerators();

		if (nums.size() == 1) {
			x0 = b1;
		}
		else {
			if (nums.size() % 2 == 0) {
				x0 = mMul(T(-1) * b1, nums[nums.size() - 2], mod1);
			}
			else {
				x0 = mMul(b1, nums[nums.size() - 2], mod1);
			}
		}
	}
	return Deductions<T>(x0, mod1, mod, true);
}