#include "gl2d/include/circle.h"
#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class CircleTest : public ::testing::Test {
};

TEST_F(CircleTest, Constructor) {
  double x = 2.3;
  double y = -4.5;
  double r = 2.5;

  const Point center(x, y);

  const Circle circle1(x, y, r);
  const Circle circle2(center, r);

  EXPECT_EQ(circle1.center_, center);
  EXPECT_DOUBLE_EQ(circle1.radius_, r);

  EXPECT_EQ(circle2.center_, center);
  EXPECT_DOUBLE_EQ(circle2.radius_, r);
}

TEST_F(CircleTest, Getters) {
  double x = 2.3;
  double y = -4.5;
  double r = 2.5;

  const Point center(x, y);

  const Circle circle(center, r);

  EXPECT_EQ(circle.Center(), center);
  EXPECT_DOUBLE_EQ(circle.Radius(), r);
}

TEST_F(CircleTest, Setters) {
  double x = 2.3;
  double y = -4.5;
  double r = 2.5;

  const Point center(x, y);

  Circle circle1(0, 0, 0);
  circle1.Center(center);
  circle1.Radius(r);

  Circle circle2(0, 0, 0);
  circle2.Center(x, y);
  circle2.Radius(r);

  EXPECT_EQ(circle1.center_, center);
  EXPECT_DOUBLE_EQ(circle1.radius_, r);

  EXPECT_EQ(circle2.center_, center);
  EXPECT_DOUBLE_EQ(circle2.radius_, r);
}

TEST_F(CircleTest, Translation) {
  Circle circle(0, 0, 1);

  Circle answer1(2, 3, 1);
  Circle answer2(0, 0, 1);

  circle.Translate(Vector(2, 3));
  EXPECT_EQ(circle, answer1);

  circle.Translate(Vector(-2, -3));
  EXPECT_EQ(circle, answer2);
}

TEST_F(CircleTest, OperatorEqual) {
  Circle circle1(0, 0, 1);
  Circle circle2(2, 2, 1);
  Circle circle3(0, 0, 2);

  EXPECT_TRUE(circle1 == circle1);
  EXPECT_FALSE(circle1 == circle2);
  EXPECT_FALSE(circle1 == circle3);
}

TEST_F(CircleTest, OperatorNotEqual) {
  Circle circle1(0, 0, 1);
  Circle circle2(2, 2, 1);
  Circle circle3(0, 0, 2);

  EXPECT_TRUE(circle1 != circle2);
  EXPECT_TRUE(circle1 != circle3);
  EXPECT_FALSE(circle1 != circle1);
}

}  // namespace gl2d
