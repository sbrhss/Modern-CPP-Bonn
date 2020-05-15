#include <gtest/gtest.h>
#include <digit_counter/digit_counting.hpp>
#include <cmath>

using namespace digitCounting;

TEST(TestDigit, SignificantBothGreater) {
  double a = 1.34567823;
  double b = 2.34568888;

  EXPECT_EQ(CountSameSignificantDigits(a, b), 0);
}

TEST(TestDigit, OneGreater) {
  double a = 1.34567823;
  double b = 0.34568888;

  EXPECT_EQ(CountSameSignificantDigits(a, b), -1);
}

TEST(TestDigit, DifferentSigns) {
  double a = -1.000;
  double b = 1.000;

  EXPECT_EQ(CountSameSignificantDigits(a, b), -2);
}

TEST(TestDigit, Warp) {
  double pi = 3.14159265;
  double factor = 1e17;

  double pi_warped = Warp(pi, factor);
  EXPECT_FALSE(std::fabs(pi - pi_warped) < 1e-2);
}

TEST(TestDigit, DontWarp) {
  double pi = 3.14159265;
  double factor = 1e10;

  double pi_warped = Warp(pi, factor);
  EXPECT_TRUE(std::fabs(pi - pi_warped) < 1e-2);
}

TEST(TestDigit, SignificantEqual) {
  double a = 0.34567823;
  double b = a;

  EXPECT_EQ(CountSameSignificantDigits(a, b), 100);
}


TEST(TestDigit, SignificantDifferent) {
  double a = 0.121314156;
  double b = 0.121314157;

  EXPECT_EQ(CountSameSignificantDigits(a, b), 8);
}
