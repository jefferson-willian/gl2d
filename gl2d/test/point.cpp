#include <iostream>

#include "gl2d/include/point.h"
#include "gtest/gtest.h"

namespace gl2d {

class PointTest : public ::testing::Test {
};

TEST_F(PointTest, Constructor) {
  double x1 = 2.3;
  double y1 = -4.5;

  const Point p1(x1, y1);

  EXPECT_DOUBLE_EQ(x1, p1.x_);
  EXPECT_DOUBLE_EQ(y1, p1.y_);
}

TEST_F(PointTest, Getters) {
  double x = 2.3;
  double y = -4.5;

  const Point p(x, y);

  EXPECT_DOUBLE_EQ(x, p.x());
  EXPECT_DOUBLE_EQ(y, p.y());
}

TEST_F(PointTest, Setters) {
  double x = 2.3;
  double y = -4.5;

  Point p(0, 0);
  p.x(x);
  p.y(y);

  EXPECT_DOUBLE_EQ(x, p.x_);
  EXPECT_DOUBLE_EQ(y, p.y_);
}

TEST_F(PointTest, OperatorEqual) {
  double x1 = 2.3;
  double y1 = -4.5;

  const Point p1(x1, y1);

  double x2 = 2.3;
  double y2 = -4.5;

  const Point p2(x2, y2);

  EXPECT_EQ(p1, p2);
}

TEST_F(PointTest, OperatorNotEqual) {
  double x1 = 2.3;
  double y1 = -4.5;

  const Point p1(x1, y1);

  double x2 = 1.3;
  double y2 = 5.5;

  const Point p2(x2, y2);

  EXPECT_NE(p1, p2);
}

TEST_F(PointTest, OperatorSum) {
  double x1 = 2.3;
  double y1 = -4.5;

  Point p1(x1, y1);

  double x2 = 1.3;
  double y2 = 5.5;

  const Point p2(x2, y2);

  const Point p3(x1 + x2, y1 + y2);

  EXPECT_EQ(p1 + p2, p3);
  EXPECT_EQ(p2 + p1, p3);
}

TEST_F(PointTest, OperatorMinus) {
  double x1 = 2.3;
  double y1 = -4.5;

  Point p1(x1, y1);

  double x2 = 1.3;
  double y2 = 5.5;

  const Point p2(x2, y2);

  const Point p3(x1 - x2, y1 - y2);

  EXPECT_EQ(p1 - p2, p3);
  EXPECT_EQ(p2 - p1, -p3);
}

TEST_F(PointTest, OperatorMultiplication) {
  double x1 = 2.3;
  double y1 = -4.5;

  Point p1(x1, y1);

  double x2 = 3 * x1;
  double y2 = 3 * y1;

  const Point p2(x2, y2);

  EXPECT_EQ(3 * p1, p2);
  EXPECT_EQ(p1 * 3, p2);
}

TEST_F(PointTest, OperatorDivision) {
  double x1 = 2.3;
  double y1 = -4.5;

  Point p1(x1, y1);

  double x2 = x1 / 3;
  double y2 = y1 / 3;

  const Point p2(x2, y2);

  EXPECT_EQ(p1 / 3, p2);
}

}  // namespace gl2d
