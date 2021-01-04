#include "module.h"
#include "BigInt.h"

#include <chrono>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

std::vector<double> example(const BigInt& a, const BigInt& b, const BigInt& mod);

std::ofstream& operator <<(std::ofstream& out, const std::vector<std::vector<double>>& table);

int main() {
    BigInt a("1365476372478247728478427842877821667676776677689898928924894298249");
    BigInt b("121373437373178784278427847878247878478427790190904109219219421949941924199417");

    size_t tests = 300;
    std::vector<std::vector<double>> table;

    BigInt mod("162137");
    for (size_t i = 1; i <= tests; ++i) {
        table.push_back(example(a, b, mod));
        mod += BigInt(17);
        std::cout << "Test " << i << " passed" << std::endl;
    }

    try {
        std::ofstream fout("table.txt");
        if (!fout) throw std::exception();

        fout << table;

        fout.close();
        std::cout << "File was filled\n";
    }
    catch (std::exception& err) {
        std::cout << "ERROR: file was not found\n";
    }

    system("pause");
    return 0;
}

std::vector<double> example(const BigInt& a, const BigInt& b, const BigInt& mod) {
    std::vector<double> time(5);

    for (size_t i = 0; i < 5; ++i) {
        auto start = std::chrono::system_clock::now();

        decision(a, b, mod, static_cast<DecisionClass>(i));

        auto end = std::chrono::system_clock::now();

        time[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    return time;
}

std::ofstream& operator <<(std::ofstream& out, const std::vector<std::vector<double>>& table) {

    out << "1" << " " << table.size() << "\n";
    out << 5 << "\n";

    for (size_t i = 0; i < 5; ++i) {
        out << static_cast<DecisionClass>(i) << " TEST'S_NUMBER TIME,ms\n";

        for (size_t j = 0; j < table.size(); ++j) {
            out << std::fixed << std::setprecision(0) << table[j][i] << " ";
        }
        out << std::endl;
    }

    return out;
}