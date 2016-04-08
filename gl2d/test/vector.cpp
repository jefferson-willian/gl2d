#include "gl2d/include/point.h"
#include "gl2d/include/radians.h"
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

  const Vector v1(x1, y1);
  const Vector v2(Point(x1, y1));
  const Vector v3(Point(x1, y1), Point(x2, y2));

  EXPECT_EQ(v1.dest_, Point(x1, y1));
  EXPECT_EQ(v2.dest_, Point(x1, y1));
  EXPECT_EQ(v3.dest_, Point(x2 - x1, y2 - y1));
}

TEST_F(VectorTest, Getters) {
  double x = 2.3;
  double y = -4.5;

  const Vector v(x, y);

  EXPECT_NEAR(x, v.x(), 1e-10);
  EXPECT_NEAR(y, v.y(), 1e-10);
  EXPECT_EQ(Point(x, y), v.Point());
}

TEST_F(VectorTest, Setters) {
  double x = 2.3;
  double y = -4.5;

  Vector v(1, 0);
  v.x(x);
  v.y(y);

  EXPECT_EQ(Point(x, y), v.dest_);
}

TEST_F(VectorTest, Magnitude) {
  Vector v(3, -4);

  EXPECT_NEAR(v.Magnitude(), 5, 1e-10);
}

TEST_F(VectorTest, Normalize) {
  Vector v(3, -4);
  v.Normalize();

  EXPECT_EQ(v.dest_, Point(0.6, -0.8));
}

TEST_F(VectorTest, Angle) {
  const Vector v1(3, 0);
  const Vector v2(3, 3);
  const Vector v3(0, 3);
  const Vector v4(-3, 3);
  const Vector v5(-3, 0);
  const Vector v6(-3, -3);
  const Vector v7(0, -3);
  const Vector v8(3, -3);

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
  const Vector v1(0, 3);
  const Vector v2(-3, 0);
  const Vector v3(0, -3);
  const Vector v4(3, 0);

  Radians d90(Radians::PI / 2);

  Vector v(3, 0);

  v.Rotate(d90);
  EXPECT_EQ(v1.dest_, v.dest_);

  v.Rotate(d90);
  EXPECT_EQ(v2.dest_, v.dest_);

  v.Rotate(d90);
  EXPECT_EQ(v3.dest_, v.dest_);

  v.Rotate(d90);
  EXPECT_EQ(v4.dest_, v.dest_);
}

TEST_F(VectorTest, Addition) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  const Vector v1 = Vector(x1, y1) + Vector(x2, y2);
  const Vector v2 = +v1;
  Vector v3 = Vector(x1, y1);
  v3 += Vector(x2, y2);

  EXPECT_EQ(Point(x1 + x2, y1 + y2), v1.dest_);
  EXPECT_EQ(Point(x1 + x2, y1 + y2), v2.dest_);
  EXPECT_EQ(Point(x1 + x2, y1 + y2), v3.dest_);
}

TEST_F(VectorTest, Subtraction) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  const Vector v1 = Vector(x1, y1) - Vector(x2, y2);
  const Vector v2 = -v1;
  Vector v3 = Vector(x1, y1);
  v3 -= Vector(x2, y2);

  EXPECT_EQ(Point(x1 - x2, y1 - y2), v1.dest_);
  EXPECT_EQ(Point(x2 - x1, y2 - y1), v2.dest_);
  EXPECT_EQ(Point(x1 - x2, y1 - y2), v3.dest_);
}

TEST_F(VectorTest, ScalarProduct) {
  double x = 2.3;
  double y = -4.5;

  double k = 3.5;

  const Vector v1 = Vector(x, y) * k;
  const Vector v2 = k * Vector(x, y);
  Vector v3 = Vector(x, y);
  v3 *= k;

  EXPECT_EQ(Point(x * k, y * k), v1.dest_);
  EXPECT_EQ(Point(x * k, y * k), v2.dest_);
  EXPECT_EQ(Point(x * k, y * k), v3.dest_);
}

TEST_F(VectorTest, ScalarDivision) {
  double x = 2.3;
  double y = -4.5;

  double k = 3.5;

  const Vector v1 = Vector(x, y) / k;
  Vector v2 = Vector(x, y);
  v2 /= k;

  EXPECT_EQ(Point(x / k, y / k), v1.dest_);
  EXPECT_EQ(Point(x / k, y / k), v2.dest_);
}

TEST_F(VectorTest, EqualOperator) {
  const Vector v1(2.3, -4.5);
  const Vector v2(1.3, -4.5);
  const Vector v3(2.3, -2.5);

  EXPECT_TRUE(v1 == v1);
  EXPECT_FALSE(v1 == v2);
  EXPECT_FALSE(v1 == v3);
}

TEST_F(VectorTest, NotEqualOperator) {
  const Vector v1(2.3, -4.5);
  const Vector v2(1.3, -4.5);
  const Vector v3(2.3, -2.5);

  EXPECT_FALSE(v1 != v1);
  EXPECT_TRUE(v1 != v2);
  EXPECT_TRUE(v1 != v3);
}

TEST_F(VectorTest, Canonical) {
  EXPECT_EQ(Point(1, 0), Vector::i.dest_);
  EXPECT_EQ(Point(0, 1), Vector::j.dest_);
}

}  // namespace gl2d
