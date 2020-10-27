#pragma once

#include <vector>
#include <sstream>

// �����, ���������� �������
class Leftovers {
public:
	explicit Leftovers();
	explicit Leftovers(const std::vector<long long>& newLeftovers);

	std::vector<long long> getLeftovers() const;

private:
	const std::vector<long long> leftovers;
};

// �����, ���������� ������
class Module {
public:
	explicit Module();
	explicit Module(const long long& newModule);

	long long getModule() const;

private:
	const long long module;
};

// �����, ���������� ������� ��������� a*x = b(mod m)
class Deductions {
public:
	explicit Deductions();
	explicit Deductions(const Leftovers& newLeftovers, const Module& newModule);

	friend std::ostream& operator <<(std::ostream& out, const Deductions& outDeductions);

private:
	Leftovers leftovers;
	Module module;
};


// ������� ��������� � ������� �� ������
long long mFastPow(const long long& a, const long long& n, const long long& mod);

// ����� �� ������
long long mSum(const long long& a, const long long& b, const long long& mod);

// �������� �� ������
long long mDif(const long long& a, const long long& b, const long long& mod);

// ��������� �� ������
long long mMul(const long long& a, const long long& b, const long long& mod);

// �������� �������
long long gcd(const long long& a, const long long& b);

// ����������� �������� �������
long long extgcd(const long long& a, const long long& b, long long& x, long long& y);

// ������� ������ �� ������
long long EulerFunction(const long long& number);

// ������� ��������� a*x = b(mod m)
Deductions decision(const long long& a, const long long& b, const long long& mod, const int numbOfDecision);