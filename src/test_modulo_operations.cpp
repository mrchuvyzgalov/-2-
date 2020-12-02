#include "modulo_operations.h"
#include "test_modulo_operations.h"
#include "UnitTestFramework.h"

void TestAllOperations() {
    TestFastPow();
    TestSum();
    TestDif();
    TestMul();
    TestGcd();
    TestExtgcd();
    TestEulerFunction();
}

void TestFastPow() {
    {
        AssertEqual(mFastPow(0, 1, 10), 0, "TestFastPow #1");
    }
    
    {
        AssertEqual(mFastPow(-5, 1, 10), -5, "TestFastPow #2");
    }

    {
        AssertEqual(mFastPow(-5, 2, 10), 5, "TestFastPow #3");
    }

    {
        AssertEqual(mFastPow(3, 4, 100), 81, "TestFastPow #4");
    }
}

void TestSum() {
    {
        AssertEqual(mSum(0, 1, 10), 1, "TestSum #1");
    }

    {
        AssertEqual(mSum(10, 3, 10), 3, "TestSum #2");
    }

    {
        AssertEqual(mSum(10, -3, 10), 7, "TestSum #3");
    }

    {
        AssertEqual(mSum(-3, -8, 10), 9, "TestSum #4");
    }
}

void TestDif() {
    {
        AssertEqual(mDif(0, 1, 10), 9, "TestDif #1");
    }

    {
        AssertEqual(mDif(1, -5, 10), 6, "TestDif #2");
    }

    {
        AssertEqual(mDif(-10, -5, 10), 5, "TestDif #3");
    }
}

void TestMul() {
    {
        AssertEqual(mMul(0, 1, 10), 0, "TestMul #1");
    }

    {
        AssertEqual(mMul(5, 7, 10), 5, "TestMul #2");
    }

    {
        AssertEqual(mMul(-5, 1, 10), 5, "TestMul #3");
    }

    {
        AssertEqual(mMul(-5, -7, 10), 5, "TestMul #4");
    }
}

void TestGcd() {
    {
        AssertEqual(gcd(0, 5), 5, "TestGcd #1");
    }

    {
        AssertEqual(gcd(10, 5), 5, "TestGcd #2");
    }

    {
        AssertEqual(gcd(7, 5), 1, "TestGcd #3");
    }
}

void TestExtgcd() {
    {
        int x, y;
        int d = extgcd(0, 5, x, y);
        AssertEqual(0 * x + 5 * y, d, "TestExtgcd #1");
    }

    {
        int x, y;
        int d = extgcd(10, 5, x, y);
        AssertEqual(10 * x + 5 * y, d, "TestExtgcd #2");
    }

    {
        int x, y;
        int d = extgcd(7, 5, x, y);
        AssertEqual(7 * x + 5 * y, d, "TestExtgcd #3");
    }
}

void TestEulerFunction() {
    {
        AssertEqual(EulerFunction(1), 1, "TestEulerFunction #1");
    }

    {
        AssertEqual(EulerFunction(1), 1, "TestEulerFunction #1");
    }
}