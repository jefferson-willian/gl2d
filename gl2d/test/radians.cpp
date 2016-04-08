#include "gl2d/include/radians.h"
#include "gtest/gtest.h"

namespace gl2d {

class RadiansTest : public ::testing::Test {
 protected:
  const double kPiDouble = 3.14159265359;
  const double k2PiDouble = 2 * kPiDouble;

  Radians kPiRadians;
  Radians k2PiRadians;

 public:
  RadiansTest() {
    kPiRadians.radians_ = kPiDouble;
    k2PiRadians.radians_ = k2PiDouble;
  }
  ~RadiansTest() = default;
};

TEST_F(RadiansTest, Constructor) {
  Radians rad(3.14);

  EXPECT_NEAR(rad.radians_, 3.14, 1e-10);
}

TEST_F(RadiansTest, Getters) {
}

TEST_F(RadiansTest, Setters) {
}

TEST_F(RadiansTest, Normalize) {
  Radians r1(kPiDouble);
  Radians r2(-kPiDouble);
  Radians r3(k2PiDouble);
  Radians r4(-k2PiDouble);
  Radians r5(k2PiDouble * 5);
  Radians r6(-k2PiDouble * 5);
  Radians r7(k2PiDouble * 5 + kPiDouble);
  Radians r8(-k2PiDouble * 5 - kPiDouble);

  r1.Normalize();
  r2.Normalize();
  r3.Normalize();
  r4.Normalize();
  r5.Normalize();
  r6.Normalize();
  r7.Normalize();
  r8.Normalize();

  EXPECT_NEAR(r1.radians_, kPiDouble, 1e-10);
  EXPECT_NEAR(r2.radians_, -kPiDouble, 1e-10);
  EXPECT_NEAR(r3.radians_, k2PiDouble, 1e-10);
  EXPECT_NEAR(r4.radians_, -k2PiDouble, 1e-10);
  EXPECT_NEAR(r5.radians_, k2PiDouble, 1e-10);
  EXPECT_NEAR(r6.radians_, -k2PiDouble, 1e-10);
  EXPECT_NEAR(r7.radians_, kPiDouble, 1e-10);
  EXPECT_NEAR(r8.radians_, -kPiDouble, 1e-10);
}

TEST_F(RadiansTest, Addition) {
  Radians r1 = kPiRadians + kPiRadians;
  Radians r2 = kPiRadians + kPiDouble;
  Radians r3 = kPiDouble + kPiRadians;
  Radians r4 = +k2PiRadians;
  Radians r5(kPiDouble);
  r5 += kPiRadians;
  Radians r6(kPiDouble);
  r6 += kPiDouble;

  EXPECT_NEAR(r1.radians_, k2PiDouble, 1e-10);
  EXPECT_NEAR(r2.radians_, k2PiDouble, 1e-10);
  EXPECT_NEAR(r3.radians_, k2PiDouble, 1e-10);
  EXPECT_NEAR(r4.radians_, k2PiDouble, 1e-10);
  EXPECT_NEAR(r5.radians_, k2PiDouble, 1e-10);
  EXPECT_NEAR(r6.radians_, k2PiDouble, 1e-10);
}

TEST_F(RadiansTest, Subtraction) {
  Radians r1 = k2PiRadians - kPiRadians;
  Radians r2 = k2PiRadians - kPiDouble;
  Radians r3 = k2PiDouble - kPiRadians;
  Radians r4 = -kPiRadians;
  Radians r5(k2PiDouble);
  r5 -= kPiRadians;
  Radians r6(k2PiDouble);
  r6 -= kPiDouble;

  EXPECT_NEAR(r1.radians_, kPiDouble, 1e-10);
  EXPECT_NEAR(r2.radians_, kPiDouble, 1e-10);
  EXPECT_NEAR(r3.radians_, kPiDouble, 1e-10);
  EXPECT_NEAR(r4.radians_, -kPiDouble, 1e-10);
  EXPECT_NEAR(r5.radians_, kPiDouble, 1e-10);
  EXPECT_NEAR(r6.radians_, kPiDouble, 1e-10);
}

TEST_F(RadiansTest, Product) {
  Radians r1 = kPiRadians * k2PiDouble;
  Radians r2 = k2PiDouble * kPiRadians;
  Radians r3 = kPiRadians * k2PiRadians;
  Radians r4(k2PiDouble);
  r4 *= kPiDouble;
  Radians r5(k2PiDouble);
  r5 *= kPiRadians;

  EXPECT_NEAR(r1.radians_, k2PiDouble * kPiDouble, 1e-10);
  EXPECT_NEAR(r2.radians_, k2PiDouble * kPiDouble, 1e-10);
  EXPECT_NEAR(r3.radians_, k2PiDouble * kPiDouble, 1e-10);
  EXPECT_NEAR(r4.radians_, k2PiDouble * kPiDouble, 1e-10);
  EXPECT_NEAR(r5.radians_, k2PiDouble * kPiDouble, 1e-10);
}

TEST_F(RadiansTest, Division) {
  Radians r1 = kPiRadians / k2PiDouble;
  Radians r2 = kPiDouble / k2PiRadians;
  Radians r3 = kPiRadians / k2PiRadians;
  Radians r4(kPiDouble);
  r4 /= k2PiDouble;
  Radians r5(kPiDouble);
  r5 /= k2PiRadians;

  EXPECT_NEAR(r1.radians_, 0.5, 1e-10);
  EXPECT_NEAR(r2.radians_, 0.5, 1e-10);
  EXPECT_NEAR(r3.radians_, 0.5, 1e-10);
  EXPECT_NEAR(r4.radians_, 0.5, 1e-10);
  EXPECT_NEAR(r5.radians_, 0.5, 1e-10);
}

TEST_F(RadiansTest, EqualOperator) {
  // TODO(user)
}

TEST_F(RadiansTest, NotEqualOperator) {
  // TODO(user)
}

TEST_F(RadiansTest, DoubleAssignment) {
  Radians rad;
  rad = kPiDouble;

  EXPECT_NEAR(rad.radians_, kPiDouble, 1e-10);
}

TEST_F(RadiansTest, Cosine) {
  Radians r1(kPiDouble * 0);
  Radians r2(kPiDouble * 0.5);
  Radians r3(kPiDouble * 1);
  Radians r4(kPiDouble * 1.5);

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
  Radians r1(kPiDouble * 0);
  Radians r2(kPiDouble * 0.5);
  Radians r3(kPiDouble * 1);
  Radians r4(kPiDouble * 1.5);

  double answer1 = 0;
  double answer2 = 1;
  double answer3 = 0;
  double answer4 = -1;

  EXPECT_NEAR(Radians::Sin(r1), answer1, 1e-10);
  EXPECT_NEAR(Radians::Sin(r2), answer2, 1e-10);
  EXPECT_NEAR(Radians::Sin(r3), answer3, 1e-10);
  EXPECT_NEAR(Radians::Sin(r4), answer4, 1e-10);
}

TEST_F(RadiansTest, ArcCosine) {
  double value1 = 1;
  double value2 = 0.70710678118;
  double value3 = 0;
  double value4 = -0.70710678118;
  double value5 = -1;

  EXPECT_NEAR(0. / 4 * kPiDouble, Radians::Acos(value1).radians_, 1e-10);
  EXPECT_NEAR(1. / 4 * kPiDouble, Radians::Acos(value2).radians_, 1e-10);
  EXPECT_NEAR(2. / 4 * kPiDouble, Radians::Acos(value3).radians_, 1e-10);
  EXPECT_NEAR(3. / 4 * kPiDouble, Radians::Acos(value4).radians_, 1e-10);
  EXPECT_NEAR(4. / 4 * kPiDouble, Radians::Acos(value5).radians_, 1e-10);
}

TEST_F(RadiansTest, ArcSine) {
  double value1 = 1;
  double value2 = 0.70710678118;
  double value3 = 0;
  double value4 = -0.70710678118;
  double value5 = -1;

  EXPECT_NEAR(2. / 4 * kPiDouble, Radians::Asin(value1).radians_, 1e-10);
  EXPECT_NEAR(1. / 4 * kPiDouble, Radians::Asin(value2).radians_, 1e-10);
  EXPECT_NEAR(0. / 4 * kPiDouble, Radians::Asin(value3).radians_, 1e-10);
  EXPECT_NEAR(-1. / 4 * kPiDouble, Radians::Asin(value4).radians_, 1e-10);
  EXPECT_NEAR(-2. / 4 * kPiDouble, Radians::Asin(value5).radians_, 1e-10);
}

}  // namespace gl2d
