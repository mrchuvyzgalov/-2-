#include "test_modulo_operations.h"
#include "UnitTestFramework.h"

void TestAll();

int main() {
    TestAll();
    return 0;
}

void TestAll() {
    TestRunner tr;

    tr.RunTest(TestAllOperations, "Test All Operations");
}