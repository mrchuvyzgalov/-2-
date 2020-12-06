#pragma once

#include <vector>
#include <stdexcept>
#include <cmath>

template <class T>
class Fraction
{
public:
	explicit Fraction(const T numerator = 0, const T denominator = 1);

	T get_numerator() const noexcept;
	T get_denominator() const noexcept;

	std::vector<T> get_elems() const noexcept;
	std::vector<T> get_numerators() const noexcept;
	std::vector<T> get_denominators() const noexcept;

	template<class V>
	friend Fraction<V> operator +(const Fraction<V>& first, const Fraction<V>& second);

	template<class V>
	friend Fraction<V> operator -(const Fraction<V>& first, const Fraction<V>& second);
	
	template<class V>
	friend Fraction<V> operator *(const Fraction<V>& first, const Fraction<V>& second);

	template<class V>
	friend Fraction<V> operator /(const Fraction<V>& first, const Fraction<V>& second);

	template<class V>
	friend bool operator <(const Fraction<V>& first, const Fraction<V>& second);

	template<class V>
	friend bool operator <=(const Fraction<V>& first, const Fraction<V>& second);

	template<class V>
	friend bool operator >(const Fraction<V>& first, const Fraction<V>& second);

	template<class V>
	friend bool operator >=(const Fraction<V>& first, const Fraction<V>& second);

	template<class V>
	friend bool operator ==(const Fraction<V>& first, const Fraction<V>& second);

	template<class V>
	friend bool operator !=(const Fraction<V>& first, const Fraction<V>& second);

	static T gcd(T first, T second) noexcept;

private:
	void fill_elems(T num, T den);
	void fill_numerators_denominators();

private:
	T numerator_;
	T denominator_; 

	std::vector<T> elems_;
	std::vector<T> numerators_;
	std::vector<T> denominators_;
};

template <class T>
Fraction<T>::Fraction(const T numerator, const T denominator) {
	if (denominator == 0) throw std::runtime_error("ERROR: denominator = 0\n");

	T gcd_num_den = gcd(std::abs(numerator), std::abs(denominator));

	numerator_ = numerator / gcd_num_den;
	denominator_ = denominator / gcd_num_den;

	if (denominator < 0) {
		numerator_ *= -1;
		denominator_ *= -1;
	}

	fill_elems(numerator_, denominator_);
	fill_numerators_denominators();
}

template <class T>
T Fraction<T>::get_numerator() const noexcept {
	return numerator_;
}

template <class T>
T Fraction<T>::get_denominator() const noexcept {
	return denominator_;
}

template <class T>
std::vector<T> Fraction<T>::get_elems() const noexcept {
	return elems_;
}

template <class T>
std::vector<T> Fraction<T>::get_numerators() const noexcept {
	return numerators_;
}

template <class T>
std::vector<T> Fraction<T>::get_denominators() const noexcept {
	return denominators_;
}

template <class V>
Fraction<V> operator +(const Fraction<V>& first, const Fraction<V>& second) {
	return Fraction(first.numerator_ * second.denominator_ + second.numerator_ * first.denominator_, first.denominator_ * second.denominator_);
}

template <class V>
Fraction<V> operator -(const Fraction<V>& first, const Fraction<V>& second) {
	return Fraction(first.numerator_ * second.denominator_ - second.numerator_ * first.denominator_, first.denominator_ * second.denominator_);
}

template <class V>
Fraction<V> operator *(const Fraction<V>& first, const Fraction<V>& second) {
	return Fraction(first.numerator_ * second.numerator_, first.denominator_ * second.denominator_);
}

template <class V>
Fraction<V> operator /(const Fraction<V>& first, const Fraction<V>& second) {
	return first * Fraction(second.denominator_, second.numerator_);
}

template <class V>
bool operator <(const Fraction<V>& first, const Fraction<V>& second) {
	return first.numerator_ * second.denominator_ < first.denominator_* second.numerator_;
}

template <class V>
bool operator <=(const Fraction<V>& first, const Fraction<V>& second) {
	return first < second || first == second;
}

template <class V>
bool operator >(const Fraction<V>& first, const Fraction<V>& second) {
	return second < first;
}

template <class V>
bool operator >=(const Fraction<V>& first, const Fraction<V>& second) {
	return !(first < second);
}

template <class V>
bool operator ==(const Fraction<V>& first, const Fraction<V>& second) {
	return first.numerator_ == second.numerator_ && first.denominator_ == second.denominator_ ;
}

template <class V>
bool operator !=(const Fraction<V>& first, const Fraction<V>& second) {
	return !(first == second);
}

template <class T>
T Fraction<T>::gcd(T first, T second) noexcept {
	if (first < second) return gcd(second, first);
	if (second == 0) return first;
	return gcd(second, first % second);
}

template <class T>
void Fraction<T>::fill_elems(T num, T den) {
	T q = num / den;
	T r = num - q * den;

	if (r < 0) {
		q--;
		r += den;
	}

	elems_.push_back(q);

	if (r > 0) {
		fill_elems(den, r);
	}
}

template <class T>
void Fraction<T>::fill_numerators_denominators() {
	if (elems_.size() > 0) {
		numerators_.resize(elems_.size());
		denominators_.resize(elems_.size());

		numerators_[0] = elems_[0];
		denominators_[0] = 1;

		if (elems_.size() > 1) {
			numerators_[1] = numerators_[0] * elems_[1] + 1;
			denominators_[1] = denominators_[0] * elems_[1];

			for (size_t i = 2; i < elems_.size(); ++i) {
				numerators_[i] = numerators_[i - 1] * elems_[i] + numerators_[i - 2];
				denominators_[i] = denominators_[i - 1] * elems_[i] + denominators_[i - 2];
			}
		}
	}
}