#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class PointTest : public ::testing::Test {
 protected:
  Point kP1;
  Point kP2;

  Point p0_;
  Point p1_;
  Point p2_;
  Point p3_;
  Point p4_;
  Point p5_;

  double kX1 = 2.3;
  double kY1 = -4.5;

  double kX2 = 1.3;
  double kY2 = 5.5;

  virtual void SetUp() {
    p0_.x_ = 2.3;
    p0_.y_ = -4.5;

    p1_.x_ = 2.3;
    p1_.y_ = 5.5;

    p2_.x_ = 1.3;
    p2_.y_ = -4.5;

    p3_.x_ = 1.3;
    p3_.y_ = 5.5;

    p4_.x_ = 3.6;
    p4_.y_ = 1;

    p5_.x_ = -2.3;
    p5_.y_ = 4.5;
  }

  virtual void ExpectEqual(const Point& p1, const Point& p2) {
    EXPECT_NEAR(p1.x_, p2.x_, 1e-10);
    EXPECT_NEAR(p1.y_, p2.y_, 1e-10);
  }

  virtual void AssertEqual(const Point& p1, const Point& p2) {
    ASSERT_NEAR(p1.x_, p2.x_, 1e-10);
    ASSERT_NEAR(p1.y_, p2.y_, 1e-10);
  }

  virtual void AssertAssignment(Point* p1, const Point& p2) {
    ASSERT_FALSE(p1 == nullptr);
    p1->x_ = p2.x_;
    p1->y_ = p2.y_;
    AssertEqual(*p1, p2);
  }

 public:
  PointTest() {
    kP1.x_ = kX1;
    kP1.y_ = kY1;

    kP2.x_ = kX2;
    kP2.y_ = kY2;
  }
};

TEST_F(PointTest, Constructor) {
  const Point p1(2.3, -4.5);

  ExpectEqual(p1, p0_);
}

TEST_F(PointTest, Getters) {
  EXPECT_NEAR(p0_.x(), 2.3, 1e-10);
  EXPECT_NEAR(p0_.y(), -4.5, 1e-10);
}

TEST_F(PointTest, Setters) {
  Point p1;
  Point p2;

  AssertAssignment(&p1, p0_);
  AssertAssignment(&p2, p0_);

  p1.y(5.5);
  ExpectEqual(p1, p1_);

  p2.x(1.3);
  ExpectEqual(p2, p2_);
}

TEST_F(PointTest, Translation) {
  p0_.Translate(Vector(-1, 10));

  ExpectEqual(p0_, p3_);
}

TEST_F(PointTest, Addition) {
  Point p1;
  Point p2;
  Point p3;

  AssertAssignment(&p1, p0_ + p3_);
  AssertAssignment(&p2, +p4_);
  AssertAssignment(&p3, p0_);
  p3 += p3_;

  ExpectEqual(p1, p4_);
  ExpectEqual(p2, p4_);
  ExpectEqual(p3, p4_);
}

TEST_F(PointTest, Subtraction) {
  Point p1;
  Point p2;
  Point p3;

  AssertAssignment(&p1, p4_ - p3_);
  AssertAssignment(&p2, -p0_);
  AssertAssignment(&p3, p4_);
  p3 -= p3_;

  ExpectEqual(p1, p0_);
  ExpectEqual(p2, p5_);
  ExpectEqual(p3, p0_);
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
