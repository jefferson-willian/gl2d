#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class PointTest : public ::testing::Test {
};

TEST_F(PointTest, Constructor) {
  double x = 2.3;
  double y = -4.5;

  const Point p(x, y);

  EXPECT_NEAR(x, p.x_, 1e-10);
  EXPECT_NEAR(y, p.y_, 1e-10);
}

TEST_F(PointTest, Getters) {
  double x = 2.3;
  double y = -4.5;

  const Point p(x, y);

  EXPECT_NEAR(x, p.x(), 1e-10);
  EXPECT_NEAR(y, p.y(), 1e-10);
}

TEST_F(PointTest, Setters) {
  double x = 2.3;
  double y = -4.5;

  Point p(0, 0);
  p.x(x);
  p.y(y);

  EXPECT_NEAR(x, p.x_, 1e-10);
  EXPECT_NEAR(y, p.y_, 1e-10);
}

TEST_F(PointTest, Translation) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  Point p(x1, y1);

  p.Translate(Vector(x2, y2));

  EXPECT_NEAR(x1 + x2, p.x_, 1e-10);
  EXPECT_NEAR(y1 + y2, p.y_, 1e-10);
}

TEST_F(PointTest, Addition) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  const Point p1 = Point(x1, y1) + Point(x2, y2);
  const Point p2 = +p1;
  Point p3 = Point(x1, y1);
  p3 += Point(x2, y2);

  EXPECT_NEAR(x1 + x2, p1.x_, 1e-10);
  EXPECT_NEAR(y1 + y2, p1.y_, 1e-10);

  EXPECT_NEAR(x1 + x2, p2.x_, 1e-10);
  EXPECT_NEAR(y1 + y2, p2.y_, 1e-10);

  EXPECT_NEAR(x1 + x2, p3.x_, 1e-10);
  EXPECT_NEAR(y1 + y2, p3.y_, 1e-10);
}

TEST_F(PointTest, Subtraction) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = 1.3;
  double y2 = 5.5;

  const Point p1 = Point(x1, y1) - Point(x2, y2);
  const Point p2 = -p1;
  Point p3 = Point(x1, y1);
  p3 -= Point(x2, y2);

  EXPECT_NEAR(x1 - x2, p1.x_, 1e-10);
  EXPECT_NEAR(y1 - y2, p1.y_, 1e-10);

  EXPECT_NEAR(x2 - x1, p2.x_, 1e-10);
  EXPECT_NEAR(y2 - y1, p2.y_, 1e-10);

  EXPECT_NEAR(x1 - x2, p3.x_, 1e-10);
  EXPECT_NEAR(y1 - y2, p3.y_, 1e-10);
}

TEST_F(PointTest, Multiplication) {
  double x = 2.3;
  double y = -4.5;

  double k = 3.5;

  const Point p1 = Point(x, y) * k;
  const Point p2 = k * Point(x, y);
  Point p3 = Point(x, y);
  p3 *= k;

  EXPECT_NEAR(x * k, p1.x_, 1e-10);
  EXPECT_NEAR(y * k, p1.y_, 1e-10);

  EXPECT_NEAR(x * k, p2.x_, 1e-10);
  EXPECT_NEAR(y * k, p2.y_, 1e-10);

  EXPECT_NEAR(x * k, p3.x_, 1e-10);
  EXPECT_NEAR(y * k, p3.y_, 1e-10);
}

TEST_F(PointTest, Division) {
  double x = 2.3;
  double y = -4.5;

  double k = 3.5;

  const Point p1 = Point(x, y) / k;
  Point p2 = Point(x, y);
  p2 /= k;

  EXPECT_NEAR(x / k, p1.x_, 1e-10);
  EXPECT_NEAR(y / k, p1.y_, 1e-10);

  EXPECT_NEAR(x / k, p2.x_, 1e-10);
  EXPECT_NEAR(y / k, p2.y_, 1e-10);
}

TEST_F(PointTest, OperatorEqual) {
  const Point p1(2.3, -4.5);
  const Point p2(1.3, -4.5);
  const Point p3(2.3, -2.5);

  EXPECT_TRUE(p1 == p1);
  EXPECT_FALSE(p1 == p2);
  EXPECT_FALSE(p1 == p3);
}

TEST_F(PointTest, OperatorNotEqual) {
  const Point p1(2.3, -4.5);
  const Point p2(1.3, -4.5);
  const Point p3(2.3, -2.5);

  EXPECT_FALSE(p1 != p1);
  EXPECT_TRUE(p1 != p2);
  EXPECT_TRUE(p1 != p3);
}

}  // namespace gl2d
