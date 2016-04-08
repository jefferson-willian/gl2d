#include <iostream>

#include "gl2d/include/radians.h"
#include "gtest/gtest.h"

namespace gl2d {

class RadiansTest : public ::testing::Test {
};

TEST_F(RadiansTest, Constructor) {
  Radians rad1(3.14);
  Radians rad2;

  EXPECT_DOUBLE_EQ(rad1.radians_, 3.14);
  EXPECT_DOUBLE_EQ(rad2.radians_, 0);
}

TEST_F(RadiansTest, DoubleAssignment) {
  Radians rad(0);
  rad = 3.14;

  EXPECT_DOUBLE_EQ(rad.radians_, 3.14);
}

TEST_F(RadiansTest, Addition) {
  Radians answer = Radians::TWOPI;

  double pi = 3.14159265359;

  Radians r1 = Radians::PI;
  Radians r2 = Radians::PI;
  Radians r3 = Radians::PI;

  r1 += Radians::PI;
  r2 += pi;

  EXPECT_EQ(r1, answer);
  EXPECT_EQ(r2, answer);
  EXPECT_EQ(r3 + pi, answer);
  EXPECT_EQ(pi + r3, answer);
  EXPECT_EQ(+answer,  answer);
}

TEST_F(RadiansTest, Subtraction) {
  Radians answer = Radians::PI;

  double pi = 3.14159265359;
  double twopi = 2 * pi;

  Radians r1 = Radians::TWOPI;
  Radians r2 = Radians::TWOPI;
  Radians r3 = Radians::TWOPI;
  Radians r4 = Radians::PI;
  Radians r5 = -Radians::PI;

  r1 -= Radians::PI;
  r2 -= pi;

  EXPECT_EQ(r1, answer);
  EXPECT_EQ(r2, answer);
  EXPECT_EQ(r3 - pi, answer);
  EXPECT_EQ(twopi - r4, answer);
  EXPECT_EQ(-r5,  answer);
}

TEST_F(RadiansTest, Multiplication) {
  double pi = 3.14159265359;
  double twopi = 2 * pi;
  double answer_double = pi * twopi;

  Radians answer(answer_double);

  Radians r1 = Radians::TWOPI;
  Radians r2 = Radians::TWOPI;

  r1 *= Radians::PI;
  r2 *= pi;

  EXPECT_EQ(r1, answer);
  EXPECT_EQ(r2, answer);
  EXPECT_EQ(Radians::PI * Radians::TWOPI, answer);
  EXPECT_EQ(Radians::PI * twopi, answer);
  EXPECT_EQ(pi * Radians::TWOPI, answer);
}

TEST_F(RadiansTest, Division) {
  double pi = 3.14159265359;
  double twopi = 2 * pi;
  double answer_double = twopi / pi;

  Radians answer(answer_double);

  Radians r1 = Radians::TWOPI;
  Radians r2 = Radians::TWOPI;

  r1 /= Radians::PI;
  r2 /= pi;

  EXPECT_EQ(r1, answer);
  EXPECT_EQ(r2, answer);
  EXPECT_EQ(Radians::TWOPI / Radians::PI, answer);
  EXPECT_EQ(Radians::TWOPI / pi, answer);
  EXPECT_EQ(twopi / Radians::PI, answer);
}

TEST_F(RadiansTest, Cosine) {
  Radians r1 = Radians::PI * 0;
  Radians r2 = Radians::PI * 0.5;
  Radians r3 = Radians::PI * 1;
  Radians r4 = Radians::PI * 1.5;

  double answer1 = 1;
  double answer2 = 0;
  double answer3 = -1;
  double answer4 = 0;

  EXPECT_NEAR(Radians::Cos(r1), answer1, 1e-10);
  EXPECT_NEAR(Radians::Cos(r2), answer2, 1e-10);
  EXPECT_NEAR(Radians::Cos(r3), answer3, 1e-10);
  EXPECT_NEAR(Radians::Cos(r4), answer4, 1e-10);
}

TEST_F(RadiansTest, Sine) {
  Radians r1 = Radians::PI * 0;
  Radians r2 = Radians::PI * 0.5;
  Radians r3 = Radians::PI * 1;
  Radians r4 = Radians::PI * 1.5;

  double answer1 = 0;
  double answer2 = 1;
  double answer3 = 0;
  double answer4 = -1;

  EXPECT_NEAR(Radians::Sin(r1), answer1, 1e-10);
  EXPECT_NEAR(Radians::Sin(r2), answer2, 1e-10);
  EXPECT_NEAR(Radians::Sin(r3), answer3, 1e-10);
  EXPECT_NEAR(Radians::Sin(r4), answer4, 1e-10);
}

}  // namespace gl2d
