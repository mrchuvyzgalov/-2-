#include "test_bigint.h"
#include "test_runner.h"

void test_bigint::TestBigInt() {
	TestRunner tr;

	RUN_TEST(tr, test_bigint::TestOut);
	RUN_TEST(tr, test_bigint::TestIn);
	RUN_TEST(tr, test_bigint::TestEqual);
	RUN_TEST(tr, test_bigint::TestNotEqual);
	RUN_TEST(tr, test_bigint::TestMore);
	RUN_TEST(tr, test_bigint::TestLess);
	RUN_TEST(tr, test_bigint::TestMoreEqual);
	RUN_TEST(tr, test_bigint::TestLessEqual);
	RUN_TEST(tr, test_bigint::TestSum);
	RUN_TEST(tr, test_bigint::TestDif);
	RUN_TEST(tr, test_bigint::TestSumEqual);
	RUN_TEST(tr, test_bigint::TestDifEqual);
	RUN_TEST(tr, test_bigint::TestMul);
	RUN_TEST(tr, test_bigint::TestMulEqual);
	RUN_TEST(tr, test_bigint::TestDivByTwo);
	RUN_TEST(tr, test_bigint::TestDivMod);
}

void test_bigint::TestOut() {
	{
		BigInt a("12637");
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "12637");
	}

	{
		BigInt a("-12637");
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "-12637");
	}

	{
		BigInt a("0");
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "0");
	}

	{
		BigInt a;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "0");
	}

	{
		BigInt a(126);
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "126");
	}

	{
		BigInt a(-15);
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "-15");
	}
}

void test_bigint::TestIn() {
	{
		std::stringstream ssOut("271271812");
		BigInt a;
		ssOut >> a;

		std::stringstream ssIn;
		ssIn << a;

		ASSERT_EQUAL(ssIn.str(), "271271812");
	}
	{
		std::stringstream ssOut("-271271812");
		BigInt a;
		ssOut >> a;

		std::stringstream ssIn;
		ssIn << a;

		ASSERT_EQUAL(ssIn.str(), "-271271812");
	}
}

void test_bigint::TestEqual() {
	{
		BigInt a;
		BigInt b;
		ASSERT(a == b);
	} 
	{
		BigInt a("-621781");
		BigInt b("-621781");
		ASSERT(a == b);
	}
	{
		BigInt a("621781");
		BigInt b("621781");
		ASSERT(a == b);
	}
	{
		BigInt a("-621781");
		BigInt b;
		b = a;
		ASSERT(a == b);
	}
}

void test_bigint::TestNotEqual() {
	{
		BigInt a(5);
		BigInt b;
		ASSERT(a != b);
	} 
	{
		BigInt a("-622781");
		BigInt b("-621781");
		ASSERT(a != b);
	}
	{
		BigInt a("621783");
		BigInt b("621781");
		ASSERT(a != b);
	}
	{
		BigInt a("-621781");
		BigInt b;
		ASSERT(a != b);
	}
}

void test_bigint::TestMore() {
	{
		BigInt a;
		BigInt b("0");
		ASSERT(!(a > b));
	}
	{
		BigInt a("6327");
		BigInt b("-4");
		ASSERT(a > b);
	}
	{
		BigInt a("-6327");
		BigInt b("-4");
		ASSERT(b > a);
	}
	{
		BigInt a("6327");
		BigInt b("4");
		ASSERT(a > b);
	}
}

void test_bigint::TestLess() {
	{
		BigInt a;
		BigInt b("0");
		ASSERT(!(b < a));
	}
	{
		BigInt a("6327");
		BigInt b("-4");
		ASSERT(b < a);
	}
	{
		BigInt a("-6327");
		BigInt b("-4");
		ASSERT(a < b);
	}
	{
		BigInt a("6327");
		BigInt b("4");
		ASSERT(b < a);
	}
}

void test_bigint::TestMoreEqual() {
	{
		BigInt a;
		BigInt b("0");
		ASSERT(a >= b);
	}
	{
		BigInt a("6327");
		BigInt b("-4");
		ASSERT(a >= b);
	}
	{
		BigInt a("-6327");
		BigInt b("-4");
		ASSERT(b >= a);
	}
	{
		BigInt a("6327");
		BigInt b("4");
		ASSERT(a >= b);
	}
	{
		BigInt a("362736");
		BigInt b("362736");
		ASSERT(a >= b);
	}
	{
		BigInt a("-362736");
		BigInt b("-362736");
		ASSERT(a >= b);
	}
}

void test_bigint::TestLessEqual() {
	{
		BigInt a;
		BigInt b("0");
		ASSERT(b <= a);
	}
	{
		BigInt a("6327");
		BigInt b("-4");
		ASSERT(b <= a);
	}
	{
		BigInt a("-6327");
		BigInt b("-4");
		ASSERT(a <= b);
	}
	{
		BigInt a("6327");
		BigInt b("4");
		ASSERT(b <= a);
	}
	{
		BigInt a("362736");
		BigInt b("362736");
		ASSERT(a <= b);
	}
	{
		BigInt a("-362736");
		BigInt b("-362736");
		ASSERT(a <= b);
	}
}

void test_bigint::TestSum() {
	{
		BigInt a("123456789");
		BigInt b("987654321");
		std::stringstream ss;
		ss << a + b;
		ASSERT_EQUAL(ss.str(), "1111111110");
	}
	{
		BigInt a("-123456789");
		BigInt b("-987654321");
		std::stringstream ss;
		ss << a + b;
		ASSERT_EQUAL(ss.str(), "-1111111110");
	}
	{
		BigInt a;
		BigInt b("987654321");
		std::stringstream ss;
		ss << a + b;
		ASSERT_EQUAL(ss.str(), "987654321");
	}
	{
		BigInt a;
		BigInt b("-987654321");
		std::stringstream ss;
		ss << b + a;
		ASSERT_EQUAL(ss.str(), "-987654321");
	}
	{
		BigInt a;
		BigInt b("0");
		std::stringstream ss;
		ss << b + a;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("123456789");
		BigInt b("-987654321");
		std::stringstream ss;
		ss << b + a;
		ASSERT_EQUAL(ss.str(), "-864197532");
	}
	{
		BigInt a("123456789");
		BigInt b("-987654321");
		std::stringstream ss;
		ss << a + b;
		ASSERT_EQUAL(ss.str(), "-864197532");
	}
	{
		BigInt a("-123456789");
		BigInt b("987654321");
		std::stringstream ss;
		ss << b + a;
		ASSERT_EQUAL(ss.str(), "864197532");
	}
	{
		BigInt a("-123456789");
		BigInt b("987654321");
		std::stringstream ss;
		ss << a + b;
		ASSERT_EQUAL(ss.str(), "864197532");
	}
	{
		BigInt a("123456789");
		BigInt b("-123456789");
		std::stringstream ss;
		ss << a + b;
		ASSERT_EQUAL(ss.str(), "0");
	}
}

void test_bigint::TestDif() {
	{
		BigInt a("123456789");
		BigInt b("987654321");
		std::stringstream ss;
		ss << b - a;
		ASSERT_EQUAL(ss.str(), "864197532");
	}
	{
		BigInt a("123456789");
		BigInt b("987654321");
		std::stringstream ss;
		ss << a - b;
		ASSERT_EQUAL(ss.str(), "-864197532");
	}
	{
		BigInt a("-123456789");
		BigInt b("-987654321");
		std::stringstream ss;
		ss << a - b;
		ASSERT_EQUAL(ss.str(), "864197532");
	}
	{
		BigInt a("-123456789");
		BigInt b("-987654321");
		std::stringstream ss;
		ss << b - a;
		ASSERT_EQUAL(ss.str(), "-864197532");
	}
	{
		BigInt a;
		BigInt b("-987654321");
		std::stringstream ss;
		ss << a - b;
		ASSERT_EQUAL(ss.str(), "987654321");
	}
	{
		BigInt a;
		BigInt b("-987654321");
		std::stringstream ss;
		ss << b - a;
		ASSERT_EQUAL(ss.str(), "-987654321");
	}
	{
		BigInt a;
		BigInt b("0");
		std::stringstream ss;
		ss << b - a;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("123456789");
		BigInt b("-987654321");
		std::stringstream ss;
		ss << b - a;
		ASSERT_EQUAL(ss.str(), "-1111111110");
	}
	{
		BigInt a("123456789");
		BigInt b("-987654321");
		std::stringstream ss;
		ss << a - b;
		ASSERT_EQUAL(ss.str(), "1111111110");
	}
	{
		BigInt a("-123456789");
		BigInt b("987654321");
		std::stringstream ss;
		ss << b - a;
		ASSERT_EQUAL(ss.str(), "1111111110");
	}
	{
		BigInt a("-123456789");
		BigInt b("987654321");
		std::stringstream ss;
		ss << a - b;
		ASSERT_EQUAL(ss.str(), "-1111111110");
	}
	{
		BigInt a("123456789");
		BigInt b("123456789");
		std::stringstream ss;
		ss << a - b;
		ASSERT_EQUAL(ss.str(), "0");
	}
}

void test_bigint::TestSumEqual() {
	{
		BigInt a("123456789");
		BigInt b("987654321");
		a += b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "1111111110");
	}
	{
		BigInt a("-123456789");
		BigInt b("-987654321");
		a += b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "-1111111110");
	}
	{
		BigInt a;
		BigInt b("987654321");
		a += b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "987654321");
	}
	{
		BigInt a;
		BigInt b("-987654321");
		b += a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "-987654321");
	}
	{
		BigInt a;
		BigInt b("0");
		b += a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("123456789");
		BigInt b("-987654321");
		b += a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "-864197532");
	}
	{
		BigInt a("123456789");
		BigInt b("-987654321");
		a += b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "-864197532");
	}
	{
		BigInt a("-123456789");
		BigInt b("987654321");
		b += a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "864197532");
	}
	{
		BigInt a("-123456789");
		BigInt b("987654321");
		a += b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "864197532");
	}
	{
		BigInt a("123456789");
		BigInt b("-123456789");
		a += b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "0");
	}
}

void test_bigint::TestDifEqual() {
	{
		BigInt a("123456789");
		BigInt b("987654321");
		b -= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "864197532");
	}
	{
		BigInt a("123456789");
		BigInt b("987654321");
		a -= b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "-864197532");
	}
	{
		BigInt a("-123456789");
		BigInt b("-987654321");
		a -= b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "864197532");
	}
	{
		BigInt a("-123456789");
		BigInt b("-987654321");
		b -= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "-864197532");
	}
	{
		BigInt a;
		BigInt b("-987654321");
		a -= b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "987654321");
	}
	{
		BigInt a;
		BigInt b("-987654321");
		b -= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "-987654321");
	}
	{
		BigInt a;
		BigInt b("0");
		b -= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("123456789");
		BigInt b("-987654321");
		b -= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "-1111111110");
	}
	{
		BigInt a("123456789");
		BigInt b("-987654321");
		a -= b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "1111111110");
	}
	{
		BigInt a("-123456789");
		BigInt b("987654321");
		b -= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "1111111110");
	}
	{
		BigInt a("-123456789");
		BigInt b("987654321");
		a -= b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "-1111111110");
	}
	{
		BigInt a("123456789");
		BigInt b("123456789");
		a -= b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "0");
	}
}

void test_bigint::TestAbs() {
	{
		BigInt a("6323323");
		std::stringstream ss;
		ss << Abs(a);
		ASSERT_EQUAL(ss.str(), "6323323");
	}
	{
		BigInt a("-6323323");
		std::stringstream ss;
		ss << Abs(a);
		ASSERT_EQUAL(ss.str(), "6323323");
	}
	{
		BigInt a("-6323323");
		std::stringstream ss;
		ss << Abs(a);
		ASSERT_EQUAL(ss.str(), "6323323");
	}
}

void test_bigint::TestMul() {
	{
		BigInt a;
		BigInt b;
		std::stringstream ss;
		ss << a * b;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("362732");
		BigInt b;
		std::stringstream ss;
		ss << a * b;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("362732");
		BigInt b;
		std::stringstream ss;
		ss << b * a;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("362732");
		BigInt b("2162");
		std::stringstream ss;
		ss << b * a;
		ASSERT_EQUAL(ss.str(), "784226584");
	}
	{
		BigInt a("-362732");
		BigInt b("2162");
		std::stringstream ss;
		ss << b * a;
		ASSERT_EQUAL(ss.str(), "-784226584");
	}
}

void test_bigint::TestMulEqual() {
	{
		BigInt a;
		BigInt b;
		a *= b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("362732");
		BigInt b;
		a *= b;
		std::stringstream ss;
		ss << a;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("362732");
		BigInt b;
		b *= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("362732");
		BigInt b("2162");
		b *= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "784226584");
	}
	{
		BigInt a("-362732");
		BigInt b("2162");
		b *= a;
		std::stringstream ss;
		ss << b;
		ASSERT_EQUAL(ss.str(), "-784226584");
	}
}

void test_bigint::TestDivByTwo() {
	{
		BigInt a("125612");
		std::stringstream ss;
		ss << DivByTwo(a);
		ASSERT_EQUAL(ss.str(), "62806");
	}
	{
		BigInt a;
		std::stringstream ss;
		ss << DivByTwo(a);
		ASSERT_EQUAL(ss.str(), "0");
	}
	{
		BigInt a("-125612");
		std::stringstream ss;
		ss << DivByTwo(a);
		ASSERT_EQUAL(ss.str(), "-62806");
	}
	{
		BigInt a("125613");
		std::stringstream ss;
		ss << DivByTwo(a);
		ASSERT_EQUAL(ss.str(), "62806");
	}
	{
		BigInt a("-125613");
		std::stringstream ss;
		ss << DivByTwo(a);
		ASSERT_EQUAL(ss.str(), "-62806");
	}
}

void test_bigint::TestDivMod() {
	{
		BigInt a("1234");
		BigInt b("35");
		std::tuple<BigInt, BigInt> t = DivMod(a, b);
		BigInt div = std::get<0>(t);
		BigInt mod = std::get<1>(t);
		std::stringstream smod, sdiv;
		sdiv << div;
		smod << mod;
		ASSERT_EQUAL(sdiv.str(), "35");
		ASSERT_EQUAL(smod.str(), "9");
	}
	{
		BigInt a("-1234");
		BigInt b("35");
		std::tuple<BigInt, BigInt> t = DivMod(a, b);
		BigInt div = std::get<0>(t);
		BigInt mod = std::get<1>(t);
		std::stringstream smod, sdiv;
		sdiv << div;
		smod << mod;
		ASSERT_EQUAL(sdiv.str(), "-35");
		ASSERT_EQUAL(smod.str(), "-9");
	}
	{
		BigInt a("-1234");
		BigInt b("-35");
		std::tuple<BigInt, BigInt> t = DivMod(a, b);
		BigInt div = std::get<0>(t);
		BigInt mod = std::get<1>(t);
		std::stringstream smod, sdiv;
		sdiv << div;
		smod << mod;
		ASSERT_EQUAL(sdiv.str(), "35");
		ASSERT_EQUAL(smod.str(), "-9");
	}
	{
		BigInt a("1234");
		BigInt b("-35");
		std::tuple<BigInt, BigInt> t = DivMod(a, b);
		BigInt div = std::get<0>(t);
		BigInt mod = std::get<1>(t);
		std::stringstream smod, sdiv;
		sdiv << div;
		smod << mod;
		ASSERT_EQUAL(sdiv.str(), "-35");
		ASSERT_EQUAL(smod.str(), "9");
	}
	{
		BigInt a;
		BigInt b("-35");
		std::tuple<BigInt, BigInt> t = DivMod(a, b);
		BigInt div = std::get<0>(t);
		BigInt mod = std::get<1>(t);
		std::stringstream smod, sdiv;
		sdiv << div;
		smod << mod;
		ASSERT_EQUAL(sdiv.str(), "0");
		ASSERT_EQUAL(smod.str(), "0");
	}
	{
		BigInt a("172");
		BigInt b("-356");
		std::tuple<BigInt, BigInt> t = DivMod(a, b);
		BigInt div = std::get<0>(t);
		BigInt mod = std::get<1>(t);
		std::stringstream smod, sdiv;
		sdiv << div;
		smod << mod;
		ASSERT_EQUAL(sdiv.str(), "0");
		ASSERT_EQUAL(smod.str(), "172");
	}
	{
		BigInt a("-172");
		BigInt b("-356");
		std::tuple<BigInt, BigInt> t = DivMod(a, b);
		BigInt div = std::get<0>(t);
		BigInt mod = std::get<1>(t);
		std::stringstream smod, sdiv;
		sdiv << div;
		smod << mod;
		ASSERT_EQUAL(sdiv.str(), "0");
		ASSERT_EQUAL(smod.str(), "-172");
	}
}