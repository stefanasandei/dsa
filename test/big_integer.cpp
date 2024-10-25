//
// Created by Asandei Stefan on 11.08.2024.
//

#include <gtest/gtest.h>

#include <dsa.hpp>

class BigIntegerTest : public testing::Test {
 protected:
  BigIntegerTest() = default;

  DSA::BigInteger o{};
};

TEST_F(BigIntegerTest, SizeDefined) { EXPECT_EQ(o.GetSize(), 1); }

TEST_F(BigIntegerTest, Constructors) {
  DSA::BigInteger a(123456789);
  EXPECT_EQ(a.GetSize(), 9);
  EXPECT_STREQ(a.ToString(), "123456789");

  const char* test_str = "987654321987654321987654321987654321987654321";
  DSA::BigInteger b(test_str);
  EXPECT_EQ(b.GetSize(), strlen(test_str));
  EXPECT_STREQ(b.ToString(), test_str);

  a = b;
  EXPECT_EQ(a.GetSize(), strlen(test_str));
  EXPECT_STREQ(a.ToString(), test_str);
}

TEST_F(BigIntegerTest, ArithmeticOps) {
  DSA::BigInteger a(123456789), b("20934823097458024675");

  const char* add_res = "20934823097581481464";
  const char* sub_res = "20934823097334567886";
  const char* mul_res = "2584546038896201888658268575";

  auto c = b + a;
  EXPECT_STREQ(c.ToString(), add_res);

  auto d = b - a;
  EXPECT_STREQ(d.ToString(), sub_res);

  auto e = b * a;
  EXPECT_STREQ(e.ToString(), mul_res);
}
