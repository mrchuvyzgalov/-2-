#include "module.h"

#include <chrono>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::pair<std::vector<double>, std::string> example1();

std::ostream& operator <<(std::ostream& out, const std::pair<std::vector<double>, std::string>& example);

int main() {
    std::cout << example1() << std::endl;
    
    return 0;
}

std::ostream& operator <<(std::ostream& out, const std::pair<std::vector<double>, std::string>& example) {
    out << "Example: " << " " << example.second << ":\n";

    for (size_t i = 0; i < 5; ++i) {
        out << static_cast<DecisionClass>(i);
        out << " time: " << example.first[i] << " us " << std::endl;
    }

    return out;
}

std::pair<std::vector<double>, std::string> example1() {
    long long a = 5;
    long long b = 17;
    long long mod = 26;

    std::vector<double> time(5);
    std::string res = std::to_string(a) + " * x = " + std::to_string(b) + " (mod " + std::to_string(mod) + ")";

    for (size_t i = 0; i < 5; ++i) {
        auto start = std::chrono::system_clock::now();

        decision(a, b, mod, static_cast<DecisionClass>(i));

        auto end = std::chrono::system_clock::now();

        time[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    return std::make_pair(time, res);
}