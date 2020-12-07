#include "module.h"
#include "BigInt.h"

#include <chrono>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

std::pair<std::vector<double>, std::string> example(const std::string& a, const std::string& b, const std::string& mod);

std::ofstream& operator <<(std::ofstream& out, const std::vector<std::vector<double>>& table);

int main() {
    // a = (37**2)
    // b = (23**3)

    std::string a = "1369";
    std::string b = "12167";

    std::vector<std::vector<double>> table(98);

    for (size_t mod = 3; mod <= 100; ++mod) {
        table[mod - 3] = example(a, b, std::to_string(mod)).first;
    }

    try {
        std::ofstream fout("files/table.txt");
        if (!fout) throw std::exception();

        fout << table;

        fout.close(); 
    }
    catch (std::exception& err) {
        std::cout << "ERROR: file was not found\n";
    }

    std::cout << "File was filled\n";

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

std::ofstream& operator <<(std::ofstream& out, const std::vector<std::vector<double>>& table) {

    out << 3 << " " << 100 << "\n";
    out << 5 << "\n";

    for (size_t i = 0; i < 5; ++i) {
        out << static_cast<DecisionClass>(i) << " TIME,us\n";

        for (size_t j = 0; j < table.size(); ++j) {
            out << table[j][i] << " ";
        }
        out << std::endl;
    }

    return out;
}