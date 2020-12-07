#include "module.h"

std::ostream& operator <<(std::ostream& out, const DecisionClass& class_) {
	switch (class_) {
	case DecisionClass::EULER : out << "EULER"; break;
	case DecisionClass::BRUTE_FORCE_1 : out << "BRUTE_FORCE_1"; break;
	case DecisionClass::BRUTE_FORCE_2 : out << "BRUTE_FORCE_2"; break;
	case DecisionClass::DIOPHANTINE : out << "DIOPHANTINE"; break;
	case DecisionClass::FRACTIONS : out << "FRACTIONS"; break;
	}

	return out;
}