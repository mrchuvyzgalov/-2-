#pragma once

#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>

template <class T>
class Leftovers {
public:
	explicit Leftovers();
	explicit Leftovers(const std::vector<T>& newLeftovers);

	std::vector<T> getLeftovers() const;

private:
	const std::vector<T> leftovers;
};

template <class T>
class Module {
public:
	explicit Module();
	explicit Module(const T& newModule);

	T getModule() const;

private:
	const T module;
};


template <class T>
class Deductions {
public:
	explicit Deductions();
	explicit Deductions(const Leftovers<T>& newLeftovers, const Module<T>& newModule);

	template <class U>
	friend std::ostream& operator <<(std::ostream& out, const Deductions<U>& outDeductions);

private:
	Leftovers<T> leftovers;
	Module<T> module;
};

template <class T>
T mFastPow(const T& a, const T& n, const T& mod);

template <class T>
T mSum(const T& a, const T& b, const T& mod);

template <class T>
T mDif(const T& a, const T& b, const T& mod);

template <class T>
T mMul(const T& a, const T& b, const T& mod);

template <class T>
T gcd(const T& a, const T& b);

template <class T>
T extgcd(const T& a, const T& b, T& x, T& y);

template <class T>
T EulerFunction(const T& number);

template <class T>
Deductions<T> decision(const T& a, const T& b, const T& mod, const int numbOfDecision);



template <class T>
Leftovers<T>::Leftovers() : leftovers(std::vector<T>{}) {}

template <class T>
Leftovers<T>::Leftovers(const std::vector<T>& newLeftovers) : leftovers(newLeftovers) { }

template <class T>
std::vector<T> Leftovers<T>::getLeftovers() const { return leftovers; }

template <class T>
Module<T>::Module() : module(0) { }

template <class T>
Module<T>::Module(const T& newModule) : module(newModule) { };

template <class T>
T Module<T>::getModule() const { return module; }

template <class T>
Deductions<T>::Deductions() : leftovers(Leftovers<T>()), module(Module<T>()) { };

template <class T>
Deductions<T>::Deductions(const Leftovers<T>& newLeftovers, const Module<T>& newModule) : leftovers(newLeftovers), module(newModule) { }

template <class U>
std::ostream& operator <<(std::ostream& out, const Deductions<U>& outDeductions) {
	std::vector<U> leftovers = outDeductions.leftovers.getLeftovers();
	U module = outDeductions.module.getModule();

	if (leftovers.size() == 0) out << "no decisions\n";

	for (auto curr : leftovers) { 
		out << "x = " << curr << " + " << module << " * k, k is integer\n";
	}

	return out;
}


template <class T>
T mFastPow(const T& a, const T& n, const T& mod) {
	if (n == 0) return 1;
	if (n % 2 == 1) return ((a % mod) * mFastPow(a, n - 1, mod)) % mod;

	T tmp = mFastPow(a, n / 2, mod);
	return (tmp * tmp) % mod;
}

template <class T>
T mSum(const T& a, const T& b, const T& mod) {
	return ((a % mod) + (b % mod)) % mod;
}

template <class T>
T mDif(const T& a, const T& b, const T& mod) {
	return (mod + (a % mod) - (b % mod)) % mod;
}

template <class T>
T mMul(const T& a, const T& b, const T& mod) {
	return ((a % mod) * (b % mod)) % mod;
}

template <class T>
T gcd(const T& a, const T& b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

template <class T>
T extgcd(const T& a, const T& b, T& x, T& y) {
	if (a < b) return extgcd(b, a, y, x);
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	T x1, y1;
	T d = extgcd(b, a % b, x1, y1);
	y = x1 - (a / b) * y1;
	x = y1;
	return d;
}

template <class T>
T EulerFunction(const T& number) {
	T tmpNumber = number;

	std::vector<T> arr;

	T tmpSimple = 2;
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

	T mulInArr1 = 1;
	T mulInArr2 = 1;

	for (const auto& curr : arr) {
		mulInArr1 *= curr;
		mulInArr2 *= curr - 1;
	}

	return (number * mulInArr2) / mulInArr1;
}

template <class T>
Deductions<T> decision(const T& a, const T& b, const T& mod, const int numbOfDecision) {
	T gcd_a_mod = gcd(a, mod);

	if (b % gcd_a_mod != 0) return Deductions<T>();

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

	return Deductions<T>(Leftovers<T>(leftovers), Module<T>(mod));
}