#pragma once

#include <vector>
#include <stdexcept>

template <class T>
T mFastPow(const T& a, const T& n, const T& mod);

template <class T>
T mSum(T a, T b, const T& mod);

template <class T>
T mDif(T a, T b, const T& mod);

template <class T>
T mMul(T a, T b, const T& mod);

template <class T>
T gcd(const T& a, const T& b);

template <class T>
T extgcd(const T& a, const T& b, T& x, T& y);

template <class T>
T EulerFunction(T number);



template <class T>
T mFastPow(const T& a, const T& n, const T& mod) {
	if (a < T(0) && n % T(2) != T(0)) return T(-1) * mFastPow(T(-1) * a, n, mod);
	else if (a < T(0)) return mFastPow(T(-1) * a, n, mod);

	if (n == T(0)) return T(1);
	if (n % T(2) == T(1)) return ((a % mod) * mFastPow(a, n - T(1), mod)) % mod;

	T tmp = mFastPow(a, n / T(2), mod);
	return (tmp * tmp) % mod;
}

template <class T>
T mSum(T a, T b, const T& mod) {
	if (a < T(0)) a += mod * (T(-1) * a / mod + 1);
	if (b < T(0)) b += mod * (T(-1) * b / mod + 1);

	return ((a % mod) + (b % mod)) % mod;
}

template <class T>
T mDif(T a, T b, const T& mod) {
	if (a < T(0)) a += mod * (T(-1) * a / mod + 1);
	if (b < T(0)) b += mod * (T(-1) * b / mod + 1);

	return (mod + (a % mod) - (b % mod)) % mod;
}

template <class T>
T mMul(T a, T b, const T& mod) {
	if (a < T(0)) a += mod * (T(-1) * a / mod + 1);
	if (b < T(0)) b += mod * (T(-1) * b / mod + 1);

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
	if (b == T(0)) {
		x = T(1);
		y = T(0);
		return a;
	}
	T x1, y1;
	T d = extgcd(b, a % b, x1, y1);
	y = x1 - (a / b) * y1;
	x = y1;
	return d;
}

template <class T>
T EulerFunction(T number) {
	T tmpNumber = number;

	std::vector<T> arr;

	T tmpSimple = T(2);
	while (tmpNumber > T(1)) {
		bool res = false;
		while (tmpNumber % tmpSimple == T(0)) {
			if (!res) {
				arr.push_back(tmpSimple);
				res = true;
			}
			tmpNumber /= tmpSimple;
		}
		tmpSimple++;
	}

	T mulInArr1 = T(1);
	T mulInArr2 = T(1);

	for (const auto& curr : arr) {
		mulInArr1 *= curr;
		mulInArr2 *= curr - T(1);
	}

	return (number * mulInArr2) / mulInArr1;
}