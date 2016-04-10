#include "gl2d/include/point.h"
#include "gl2d/include/radians.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class VectorTest : public ::testing::Test {
 protected:
  double kX1, kY1;
  double kX2, kY2;
  double kX3, kY3;
  double kX4, kY4;
  double kX5, kY5;
  double kX6, kY6;
  double kX7, kY7;

  Vector kV1;
  Vector kV2;
  Vector kV3;
  Vector kV4;
  Vector kV5;
  Vector kV6;
  Vector kV7;

  VectorTest() {
    kX1 = 2.3;
    kY1 = -4.5;
    kV1.dest_ = Point(kX1, kY1);
    kX2 = 1.3;
    kY2 = 5.5;
    kV2.dest_ = Point(kX2, kY2);
    kX3 = 3;
    kY3 = -4;
    kV3.dest_ = Point(kX3, kY3);
    kX4 = 0;
    kY4 = 3;
    kV4.dest_ = Point(kX4, kY4);
    kX5 = -3;
    kY5 = 0;
    kV5.dest_ = Point(kX5, kY5);
    kX6 = 0;
    kY6 = -3;
    kV6.dest_ = Point(kX6, kY6);
    kX7 = 3;
    kY7 = 0;
    kV7.dest_ = Point(kX7, kY7);
  }
};

TEST_F(VectorTest, Constructor) {
  const Vector v1(kX1, kY1);
  const Vector v2(Point(kX1, kY1));
  const Vector v3(Point(kX1, kY1), Point(kX2, kY2));

  EXPECT_EQ(v1.dest_, Point(kX1, kY1));
  EXPECT_EQ(v2.dest_, Point(kX1, kY1));
  EXPECT_EQ(v3.dest_, Point(kX2 - kX1, kY2 - kY1));
}

TEST_F(VectorTest, Getters) {
  EXPECT_NEAR(kX1, kV1.x(), 1e-10);
  EXPECT_NEAR(kY1, kV1.y(), 1e-10);
  EXPECT_EQ(Point(kX1, kY1), kV1.Point());
}

TEST_F(VectorTest, Setters) {
  Vector v;
  v.x(kX1);
  v.y(kY1);

  EXPECT_EQ(Point(kX1, kY1), v.dest_);
}

TEST_F(VectorTest, Magnitude) {
  EXPECT_NEAR(kV3.Magnitude(), 5, 1e-10);
}

TEST_F(VectorTest, Normalize) {
  EXPECT_EQ(kV3.Normalize().dest_, Point(0.6, -0.8));
}

TEST_F(VectorTest, Angle) {
  EXPECT_EQ(kV4.Angle(), 1 / 2. * Radians::PI);
  EXPECT_EQ(kV5.Angle(), 2 / 2. * Radians::PI);
  EXPECT_EQ(kV6.Angle(), 3 / 2. * Radians::PI);
  EXPECT_EQ(kV7.Angle(), 0 / 2. * Radians::PI);
}

TEST_F(VectorTest, Rotation) {
  Vector v1 = kV7;
  Vector v2 = kV7;
  Vector v3 = kV7;
  Vector v4 = kV7;

  EXPECT_EQ(v1.Rotate(1 / 2. * Radians::PI), kV4);
  EXPECT_EQ(v2.Rotate(2 / 2. * Radians::PI), kV5);
  EXPECT_EQ(v3.Rotate(3 / 2. * Radians::PI), kV6);
  EXPECT_EQ(v4.Rotate(4 / 2. * Radians::PI), kV7);
}

TEST_F(VectorTest, Addition) {
  const Vector v1 = kV1 + kV2;
  const Vector v2 = +kV1;
  Vector v3 = kV1;
  v3 += kV2;

  EXPECT_EQ(Point(kX1 + kX2, kY1 + kY2), v1.dest_);
  EXPECT_EQ(Point(kX1, kY1), v2.dest_);
  EXPECT_EQ(Point(kX1 + kX2, kY1 + kY2), v3.dest_);
}

TEST_F(VectorTest, Subtraction) {
  const Vector v1 = kV1 - kV2;
  const Vector v2 = -kV1;
  Vector v3 = kV1;
  v3 -= kV2;

  EXPECT_EQ(Point(kX1 - kX2, kY1 - kY2), v1.dest_);
  EXPECT_EQ(Point(-kX1, -kY1), v2.dest_);
  EXPECT_EQ(Point(kX1 - kX2, kY1 - kY2), v3.dest_);
}

TEST_F(VectorTest, ScalarProduct) {
  double k = 3.5;

  const Vector v1 = kV1 * k;
  const Vector v2 = k * kV1;
  Vector v3 = kV1;
  v3 *= k;

  EXPECT_EQ(Point(kX1 * k, kY1 * k), v1.dest_);
  EXPECT_EQ(Point(kX1 * k, kY1 * k), v2.dest_);
  EXPECT_EQ(Point(kX1 * k, kY1 * k), v3.dest_);
}

TEST_F(VectorTest, ScalarDivision) {
  double k = 3.5;

  const Vector v1 = kV1 / k;
  Vector v2 = kV1;
  v2 /= k;

  EXPECT_EQ(Point(kX1 / k, kY1 / k), v1.dest_);
  EXPECT_EQ(Point(kX1 / k, kY1 / k), v2.dest_);
}

TEST_F(VectorTest, EqualOperator) {
  EXPECT_TRUE(kV1 == kV1);
  EXPECT_FALSE(kV4 == kV6);
  EXPECT_FALSE(kV5 == kV7);
}

TEST_F(VectorTest, NotEqualOperator) {
  EXPECT_FALSE(kV1 != kV1);
  EXPECT_TRUE(kV4 != kV6);
  EXPECT_TRUE(kV5 != kV7);
}

TEST_F(VectorTest, Canonical) {
  EXPECT_EQ(Point(1, 0), Vector::i.dest_);
  EXPECT_EQ(Point(0, 1), Vector::j.dest_);
}

}  // namespace gl2d
