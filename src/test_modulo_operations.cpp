#include "test_modulo_operations.h"
#include "test_runner.h"

void test_operations::TestAllOperations() {
    TestRunner tr;

    RUN_TEST(tr, test_operations::TestFastPow);
    RUN_TEST(tr, test_operations::TestSum);
    RUN_TEST(tr, test_operations::TestDif);
    RUN_TEST(tr, test_operations::TestMul);
    RUN_TEST(tr, test_operations::TestGcd);
    RUN_TEST(tr, test_operations::TestExtgcd);
    RUN_TEST(tr, test_operations::TestEulerFunction);
}

void test_operations::TestFastPow() {
    {
        ASSERT_EQUAL(mFastPow(0, 1, 11), 0);
    }
    
    {
        ASSERT_EQUAL(mFastPow(-5, 3, 11), 7);
    }

    {
        ASSERT_EQUAL(mFastPow(-5, 2, 11), 3);
    }

    {
        ASSERT_EQUAL(mFastPow(3, 4, 100), 81);
    }

    {
        ASSERT_EQUAL(mFastPow(3, 5, 100), 43);
    }
}

void test_operations::TestSum() {
    {
        ASSERT_EQUAL(mSum(10, 3, 10), 3);
    }

    {
        ASSERT_EQUAL(mSum(10, -3, 10), 7);
    }

    {
        ASSERT_EQUAL(mSum(-3, -8, 10), 9);
    }
}

void test_operations::TestDif() {
    {
        ASSERT_EQUAL(mDif(3, 7, 10), 6);
    }

    {
        ASSERT_EQUAL(mDif(5, 3, 10), 2);
    }

    {
        ASSERT_EQUAL(mDif(1, -5, 10), 6);
    }

    {
        ASSERT_EQUAL(mDif(-10, -5, 10), 5);
    }
}

void test_operations::TestMul() {
    {
        ASSERT_EQUAL(mMul(0, 1, 10), 0);
    }

    {
        ASSERT_EQUAL(mMul(5, 7, 10), 5);
    }

    {
        ASSERT_EQUAL(mMul(-5, 1, 10), 5);
    }

    {
        ASSERT_EQUAL(mMul(-5, -7, 10), 5);
    }
}

void test_operations::TestGcd() {
    {
        ASSERT_EQUAL(gcd(0, 5), 5);
    }

    {
        ASSERT_EQUAL(gcd(10, 5), 5);
    }

    {
        ASSERT_EQUAL(gcd(7, 5), 1);
    }
}

void test_operations::TestExtgcd() {
    {
        int x, y;
        int d = extgcd(0, 5, x, y);
        ASSERT_EQUAL(0 * x + 5 * y, d);
    }

    {
        int x, y;
        int d = extgcd(10, 5, x, y);
        ASSERT_EQUAL(10 * x + 5 * y, d);
    }

    {
        int x, y;
        int d = extgcd(7, 5, x, y);
        ASSERT_EQUAL(7 * x + 5 * y, d);
    }
}

void test_operations::TestEulerFunction() {
    {
        ASSERT_EQUAL(EulerFunction(1), 1);
    }

    {
        ASSERT_EQUAL(EulerFunction(17), 16);
    }

    {
        ASSERT_EQUAL(EulerFunction(10), 4);
    }
}