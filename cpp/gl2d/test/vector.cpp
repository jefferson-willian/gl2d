#include <iostream>

#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class VectorTest : public ::testing::Test {
};

TEST_F(VectorTest, Constructor) {
  double x = 2.3;
  double y = -4.5;

  const Point p(x, y);

  const Vector v1(x, y);
  const Vector v2(p);

  EXPECT_EQ(v1.dest_, p);
  EXPECT_EQ(v2.dest_, p);
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

  double x2 = 1.3;
  double y2 = 5.5;

  Vector v1(1, 0);
  v1.x(x1);
  v1.y(y1);

  Vector v2(1, 0);
  const Point p(x2, y2);
  v2.Point(p);

  EXPECT_DOUBLE_EQ(x1, v1.dest_.x());
  EXPECT_DOUBLE_EQ(y1, v1.dest_.y());
  EXPECT_EQ(p, v2.dest_);
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

TEST_F(VectorTest, OperatorSum) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  Vector v1(x1, y1);
  Vector v2(x2, y2);
  Vector v3(x1 + x2, y1 + y2);

  v1 += v2;

  EXPECT_EQ(v1, v3);
}

TEST_F(VectorTest, OperatorMinus) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  Vector v1(x1, y1);
  Vector v2(x2, y2);
  Vector v3(x1 - x2, y1 - y2);

  v1 -= v2;

  EXPECT_EQ(v1, v3);
}

TEST_F(VectorTest, OperatorScalarMultiplication) {
  double x = 2.3;
  double y = -4.5;

  Vector v1(x, y);
  Vector v2(x * 3, y * 3);

  v1 *= 3;

  EXPECT_EQ(v1, v2);
}

TEST_F(VectorTest, OperatorScalarDivision) {
  double x = 2.3;
  double y = -4.5;

  Vector v1(x, y);
  Vector v2(x / 3, y / 3);

  v1 /= 3;

  EXPECT_EQ(v1, v2);
}

TEST_F(VectorTest, OperatorEqual) {
  double x = 2.3;
  double y = -4.5;

  Vector v(x, y);

  EXPECT_EQ(v, v);
}

TEST_F(VectorTest, OperatorNotEqual) {
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
