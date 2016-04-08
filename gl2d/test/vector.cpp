#include <iostream>

#include "gl2d/include/radians.h"
#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class VectorTest : public ::testing::Test {
};

TEST_F(VectorTest, Constructor) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  const Point p1(x1, y1);
  const Point p2(x2, y2);

  const Vector v1(x1, y1);
  const Vector v2(p1);
  const Vector v3(p1, p2);

  EXPECT_EQ(v1.dest_, p1);
  EXPECT_EQ(v2.dest_, p1);
  EXPECT_EQ(v3.dest_, p2 - p1);
}

TEST_F(VectorTest, Getters) {
  double x = 2.3;
  double y = -4.5;

  const Vector v(x, y);
  const Point  p(x, y);

  EXPECT_DOUBLE_EQ(x, v.x());
  EXPECT_DOUBLE_EQ(y, v.y());
  EXPECT_EQ(p, v.Point());
}

TEST_F(VectorTest, Setters) {
  double x1 = 2.3;
  double y1 = -4.5;

  Vector v1(1, 0);
  v1.x(x1);
  v1.y(y1);

  EXPECT_DOUBLE_EQ(x1, v1.dest_.x());
  EXPECT_DOUBLE_EQ(y1, v1.dest_.y());
}

TEST_F(VectorTest, Magnitude) {
  double x = 3;
  double y = -4;

  Vector v(x, y);

  EXPECT_DOUBLE_EQ(v.Magnitude(), 5);
}

TEST_F(VectorTest, Normalize) {
  double x = 3;
  double y = -4;

  Vector v1(x, y);
  Vector v2(0.6, -0.8);

  v1.Normalize();

  EXPECT_EQ(v1, v2);
}

TEST_F(VectorTest, Angle) {
  Vector v1(3, 0);
  Vector v2(3, 3);
  Vector v3(0, 3);
  Vector v4(-3, 3);
  Vector v5(-3, 0);
  Vector v6(-3, -3);
  Vector v7(0, -3);
  Vector v8(3, -3);

  EXPECT_EQ(v1.Angle(), 0/4. * Radians::PI);
  EXPECT_EQ(v2.Angle(), 1/4. * Radians::PI);
  EXPECT_EQ(v3.Angle(), 2/4. * Radians::PI);
  EXPECT_EQ(v4.Angle(), 3/4. * Radians::PI);
  EXPECT_EQ(v5.Angle(), 4/4. * Radians::PI);
  EXPECT_EQ(v6.Angle(), 5/4. * Radians::PI);
  EXPECT_EQ(v7.Angle(), 6/4. * Radians::PI);
  EXPECT_EQ(v8.Angle(), 7/4. * Radians::PI);
}

TEST_F(VectorTest, Rotation) {
  double factor = 3;

  Vector v1 = Vector::i * factor;
  Vector v2 = Vector::j * factor;
  Vector v3 = -Vector::i * factor;
  Vector v4 = -Vector::j * factor;

  Radians d0(0);
  Radians d90(Radians::PI / 2);
  Radians d180(Radians::PI);
  Radians d270(3 * Radians::PI / 2);

  Vector v5 = Vector::i * factor;
  v5.Rotate(d0);

  Vector v6 = Vector::i * factor;
  v6.Rotate(d90);

  Vector v7 = Vector::i * factor;
  v7.Rotate(d180);

  Vector v8 = Vector::i * factor;
  v8.Rotate(d270);

  EXPECT_EQ(v1, v5);
  EXPECT_EQ(v2, v6);
  EXPECT_EQ(v3, v7);
  EXPECT_EQ(v4, v8);
}

TEST_F(VectorTest, Addition) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  Vector v1(x1, y1);
  Vector v2(x2, y2);
  Vector v3(x1 + x2, y1 + y2);

  EXPECT_EQ(v1 + v2, v3);
  EXPECT_EQ(v2 + v1, v3);
}

TEST_F(VectorTest, Subtraction) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  Vector v1(x1, y1);
  Vector v2(x2, y2);
  Vector v3(x1 - x2, y1 - y2);

  EXPECT_EQ(v1 - v2, v3);
  EXPECT_EQ(v2 - v1, -v3);
}

TEST_F(VectorTest, ScalarMultiplication) {
  double x = 2.3;
  double y = -4.5;

  double k = 3;

  Vector v1(x, y);
  Vector v2(x * k, y * k);

  EXPECT_EQ(v1 * k, v2);
  EXPECT_EQ(k * v1, v2);
}

TEST_F(VectorTest, ScalarDivision) {
  double x = 2.3;
  double y = -4.5;

  double k = 3;

  Vector v1(x, y);
  Vector v2(x / k, y / k);

  EXPECT_EQ(v1 / k, v2);
}

TEST_F(VectorTest, EqualOperator) {
  double x = 2.3;
  double y = -4.5;

  Vector v(x, y);

  EXPECT_EQ(v, v);
}

TEST_F(VectorTest, NotEqualOperator) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  Vector v1(x1, y1);
  Vector v2(x2, y2);

  EXPECT_NE(v1, v2);
}

TEST_F(VectorTest, Canonical) {
  Vector i(1, 0);
  Vector j(0, 1);

  EXPECT_EQ(i, Vector::i);
  EXPECT_EQ(j, Vector::j);
}

}  // namespace gl2d
