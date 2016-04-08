#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class PointTest : public ::testing::Test {
 protected:
  Point kP1;
  Point kP2;

  double kX1 = 2.3;
  double kY1 = -4.5;

  double kX2 = 1.3;
  double kY2 = 5.5;

 public:
  PointTest() {
    kP1.x_ = kX1;
    kP1.y_ = kY1;

    kP2.x_ = kX2;
    kP2.y_ = kY2;
  }
};

TEST_F(PointTest, Constructor) {
  const Point p(kX1, kY1);

  EXPECT_NEAR(kX1, p.x_, 1e-10);
  EXPECT_NEAR(kY1, p.y_, 1e-10);
}

TEST_F(PointTest, Getters) {
  EXPECT_NEAR(kX1, kP1.x(), 1e-10);
  EXPECT_NEAR(kY1, kP1.y(), 1e-10);
}

TEST_F(PointTest, Setters) {
  Point p;

  p.x(kX1);
  p.y(kY1);

  EXPECT_NEAR(kX1, p.x_, 1e-10);
  EXPECT_NEAR(kY1, p.y_, 1e-10);
}

TEST_F(PointTest, Translation) {
  Point p = kP1;

  p.Translate(Vector(kX2, kY2));

  EXPECT_NEAR(kX1 + kX2, p.x_, 1e-10);
  EXPECT_NEAR(kY1 + kY2, p.y_, 1e-10);
}

TEST_F(PointTest, Addition) {
  const Point p1 = kP1 + kP2;
  const Point p2 = +kP1;
  Point p3 = kP1;
  p3 += kP2;

  EXPECT_NEAR(kX1 + kX2, p1.x_, 1e-10);
  EXPECT_NEAR(kY1 + kY2, p1.y_, 1e-10);

  EXPECT_NEAR(kX1, p2.x_, 1e-10);
  EXPECT_NEAR(kY1, p2.y_, 1e-10);

  EXPECT_NEAR(kX1 + kX2, p3.x_, 1e-10);
  EXPECT_NEAR(kY1 + kY2, p3.y_, 1e-10);
}

TEST_F(PointTest, Subtraction) {
  const Point p1 = kP1 - kP2;
  const Point p2 = -kP1;
  Point p3 = kP1;
  p3 -= kP2;

  EXPECT_NEAR(kX1 - kX2, p1.x_, 1e-10);
  EXPECT_NEAR(kY1 - kY2, p1.y_, 1e-10);

  EXPECT_NEAR(-kX1, p2.x_, 1e-10);
  EXPECT_NEAR(-kY1, p2.y_, 1e-10);

  EXPECT_NEAR(kX1 - kX2, p3.x_, 1e-10);
  EXPECT_NEAR(kY1 - kY2, p3.y_, 1e-10);
}

TEST_F(PointTest, Multiplication) {
  double k = 3.5;

  const Point p1 = kP1 * k;
  const Point p2 = k * kP1;
  Point p3 = kP1;
  p3 *= k;

  EXPECT_NEAR(kX1 * k, p1.x_, 1e-10);
  EXPECT_NEAR(kY1 * k, p1.y_, 1e-10);

  EXPECT_NEAR(kX1 * k, p2.x_, 1e-10);
  EXPECT_NEAR(kY1 * k, p2.y_, 1e-10);

  EXPECT_NEAR(kX1 * k, p3.x_, 1e-10);
  EXPECT_NEAR(kY1 * k, p3.y_, 1e-10);
}

TEST_F(PointTest, Division) {
  double k = 3.5;

  const Point p1 = kP1 / k;
  Point p2 = kP1;
  p2 /= k;

  EXPECT_NEAR(kX1 / k, p1.x_, 1e-10);
  EXPECT_NEAR(kY1 / k, p1.y_, 1e-10);

  EXPECT_NEAR(kX1 / k, p2.x_, 1e-10);
  EXPECT_NEAR(kY1 / k, p2.y_, 1e-10);
}

TEST_F(PointTest, OperatorEqual) {
  Point p1, p2, p3;

  p1.x_ = 2.3;
  p1.y_ = -4.5;

  p2.x_ = 1.3;
  p2.y_ = -4.5;

  p3.x_ = 2.3;
  p3.y_ = -2.5;

  EXPECT_TRUE(p1 == p1);
  EXPECT_FALSE(p1 == p2);
  EXPECT_FALSE(p1 == p3);
}

TEST_F(PointTest, OperatorNotEqual) {
  Point p1, p2, p3;

  p1.x_ = 2.3;
  p1.y_ = -4.5;

  p2.x_ = 1.3;
  p2.y_ = -4.5;

  p3.x_ = 2.3;
  p3.y_ = -2.5;

  EXPECT_FALSE(p1 != p1);
  EXPECT_TRUE(p1 != p2);
  EXPECT_TRUE(p1 != p3);
}

}  // namespace gl2d
