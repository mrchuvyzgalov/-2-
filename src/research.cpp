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

std::ostream& operator <<(std::ostream& out, const std::pair<std::vector<double>, std::string>& example);

int main() {
    // a = (2**6) * (3**7)
    // b = (2**6) * (3**2) * 5 
    // mod = (2**6) * 3
    std::cout << example("139968", "2880", "192") << std::endl; 


    // a = (2**3) * (7**5)
    // b = (2**7) * (11**4)
    // mod = (3**2)
    std::cout << example("134456", "1874048", "9") << std::endl; 

    // a = (2**3) * (3**5)
    // b = (3**7) * (11**4)
    // mod = (3**9) * (11**2)
    std::cout << example("1944", "32019867", "2381643") << std::endl; 

    return 0;
}

std::ostream& operator <<(std::ostream& out, const std::pair<std::vector<double>, std::string>& example) {
    out << std::fixed << std::setprecision(0) << "Example: " << " " << example.second << ":\n";

    for (size_t i = 0; i < 5; ++i) {
        out << static_cast<DecisionClass>(i);
        out << " time: " << example.first[i] << " us " << std::endl;
    }

    return out;
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