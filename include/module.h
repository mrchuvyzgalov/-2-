#pragma once

#include <vector>
#include <sstream>

// класс, содержащий остатки
class Leftovers {
public:
	explicit Leftovers();
	explicit Leftovers(const std::vector<long long>& newLeftovers);

	std::vector<long long> getLeftovers() const;

private:
	const std::vector<long long> leftovers;
};

// класс, содержащий модуль
class Module {
public:
	explicit Module();
	explicit Module(const long long& newModule);

	long long getModule() const;

private:
	const long long module;
};

// класс, содержаща€ решение уравнени€ a*x = b(mod m)
class Deductions {
public:
	explicit Deductions();
	explicit Deductions(const Leftovers& newLeftovers, const Module& newModule);

	friend std::ostream& operator <<(std::ostream& out, const Deductions& outDeductions);

private:
	Leftovers leftovers;
	Module module;
};


// быстрое умножение в степень по модулю
long long mFastPow(const long long& a, const long long& n, const long long& mod);

// сумма по модулю
long long mSum(const long long& a, const long long& b, const long long& mod);

// разность по модулю
long long mDif(const long long& a, const long long& b, const long long& mod);

// умножение по модулю
long long mMul(const long long& a, const long long& b, const long long& mod);

// алгоритм ≈вклида
long long gcd(const long long& a, const long long& b);

// расширенный алгоритм ≈вклида
long long extgcd(const long long& a, const long long& b, long long& x, long long& y);

// функци€ Ёйлера по модулю
long long EulerFunction(const long long& number);

// решение уравнени€ a*x = b(mod m)
Deductions decision(const long long& a, const long long& b, const long long& mod, const int numbOfDecision);