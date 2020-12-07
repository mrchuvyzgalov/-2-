#include "module.h"
#include "BigInt.h"

#include <chrono>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::pair<std::vector<double>, std::string> example(const std::string& a, const std::string& b, const std::string& mod);

std::ostream& operator <<(std::ostream& out, const std::vector<std::vector<double>>& table);

int main() {
    // a = (37**2)
    // b = (23**3)

    std::string a = "1369";
    std::string b = "12167";

    std::vector<std::vector<double>> table(10);

    for (size_t mod = 3; mod <= 12; ++mod) {
        table[mod - 3] = example(a, b, std::to_string(mod)).first;
    }

    std::cout << table;

    return 0;
}

std::pair<std::vector<double>, std::string> example(const std::string& a, const std::string& b, const std::string& mod) {
    std::vector<double> time(5);
    std::string res = a + " * x = " + b + " (mod " + mod + ")";

    for (size_t i = 0; i < 5; ++i) {
        auto start = std::chrono::system_clock::now();

        decision(BigInt(a), BigInt(b), BigInt(mod), static_cast<DecisionClass>(i));

        auto end = std::chrono::system_clock::now();

        time[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    return std::make_pair(time, res);
}

std::ostream& operator <<(std::ostream& out, const std::vector<std::vector<double>>& table) {
    out << "Results:\n";

    out << std::setw(16) << "mod:";
    for (size_t i = 3; i <= table.size() + 2; ++i) {
        out << std::setw(10) << i << "|";
    }
    out << std::endl;

    for (size_t i = 0; i < 5; ++i) {
        out << std::setw(15) << static_cast<DecisionClass>(i) << ":";

        for (size_t j = 0; j < table.size(); ++j) {
            out << std::setw(10) << table[j][i] << "|";
        }
        out << std::endl;
    }

    return out;
}