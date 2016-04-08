#include "gl2d/include/radians.h"
#include "gtest/gtest.h"

namespace gl2d {

class RadiansTest : public ::testing::Test {
};

TEST_F(RadiansTest, Constructor) {
  Radians rad(3.14);

  EXPECT_NEAR(rad.radians_, 3.14, 1e-10);
}

TEST_F(RadiansTest, Getters) {
  Radians rad(3.14);

  EXPECT_NEAR(rad.Get(), 3.14, 1e-10);
}

TEST_F(RadiansTest, Setters) {
}

TEST_F(RadiansTest, Addition) {
  double pi = 3.14159265359;
  double twopi = 2 * pi;

  Radians r1 = Radians::PI + Radians::PI;
  Radians r2 = Radians::PI + pi;
  Radians r3 = pi + Radians::PI;
  Radians r4 = +Radians::TWOPI;
  Radians r5(pi);
  r5 += Radians::PI;
  Radians r6(pi);
  r6 += pi;

  EXPECT_NEAR(r1.radians_, twopi, 1e-10);
  EXPECT_NEAR(r2.radians_, twopi, 1e-10);
  EXPECT_NEAR(r3.radians_, twopi, 1e-10);
  EXPECT_NEAR(r4.radians_, twopi, 1e-10);
  EXPECT_NEAR(r5.radians_, twopi, 1e-10);
  EXPECT_NEAR(r6.radians_, twopi, 1e-10);
}

TEST_F(RadiansTest, Subtraction) {
  double pi = 3.14159265359;
  double twopi = 2 * pi;

  Radians r1 = Radians::TWOPI - Radians::PI;
  Radians r2 = Radians::TWOPI - pi;
  Radians r3 = twopi - Radians::PI;
  Radians r4 = -Radians::PI;
  Radians r5(twopi);
  r5 -= Radians::PI;
  Radians r6(twopi);
  r6 -= pi;

  EXPECT_NEAR(r1.radians_, pi, 1e-10);
  EXPECT_NEAR(r2.radians_, pi, 1e-10);
  EXPECT_NEAR(r3.radians_, pi, 1e-10);
  EXPECT_NEAR(r4.radians_, -pi, 1e-10);
  EXPECT_NEAR(r5.radians_, pi, 1e-10);
  EXPECT_NEAR(r6.radians_, pi, 1e-10);
}

TEST_F(RadiansTest, Product) {
  double pi = 3.14159265359;
  double twopi = 2 * pi;

  Radians r1 = Radians::PI * twopi;
  Radians r2 = twopi * Radians::PI;
  Radians r3 = Radians::PI * Radians::TWOPI;
  Radians r4(twopi);
  r4 *= pi;
  Radians r5(twopi);
  r5 *= Radians::PI;

  EXPECT_NEAR(r1.radians_, twopi * pi, 1e-10);
  EXPECT_NEAR(r2.radians_, twopi * pi, 1e-10);
  EXPECT_NEAR(r3.radians_, twopi * pi, 1e-10);
  EXPECT_NEAR(r4.radians_, twopi * pi, 1e-10);
  EXPECT_NEAR(r5.radians_, twopi * pi, 1e-10);
}

TEST_F(RadiansTest, Division) {
  double pi = 3.14159265359;
  double twopi = 2 * pi;

  Radians r1 = Radians::PI / twopi;
  Radians r2 = pi / Radians::TWOPI;
  Radians r3 = Radians::PI / Radians::TWOPI;
  Radians r4(pi);
  r4 /= twopi;
  Radians r5(pi);
  r5 /= Radians::TWOPI;

  EXPECT_NEAR(r1.radians_, 0.5, 1e-10);
  EXPECT_NEAR(r2.radians_, 0.5, 1e-10);
  EXPECT_NEAR(r3.radians_, 0.5, 1e-10);
  EXPECT_NEAR(r4.radians_, 0.5, 1e-10);
  EXPECT_NEAR(r5.radians_, 0.5, 1e-10);
}

TEST_F(RadiansTest, EqualOperator) {
  // TODO
}

TEST_F(RadiansTest, NotEqualOperator) {
  // TODO
}

TEST_F(RadiansTest, DoubleAssignment) {
  double pi = 3.14159265359;

  Radians rad;
  rad = pi;

  EXPECT_NEAR(rad.radians_, pi, 1e-10);
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
