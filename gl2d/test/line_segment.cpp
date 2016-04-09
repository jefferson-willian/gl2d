#include "gl2d/include/line_segment.h"
#include "gtest/gtest.h"

namespace gl2d {

class LineSegmentTest : public ::testing::Test {
};

TEST_F(LineSegmentTest, Constructor) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = -1.3;
  double y2 = 2.3;

  const Point p1(x1, y1);
  const Point p2(x2, y2);

  LineSegment line(p1, p2);

  EXPECT_EQ(p1, line.a_);
  EXPECT_EQ(p2, line.b_);
}

TEST_F(LineSegmentTest, Setters) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = -1.3;
  double y2 = 2.3;

  const Point p1(x1, y1);
  const Point p2(x2, y2);

  LineSegment line(Point(0, 0), Point(0, 0));

  line.a(p1);
  line.b(p2);

  EXPECT_EQ(p1, line.a_);
  EXPECT_EQ(p2, line.b_);
}

TEST_F(LineSegmentTest, Getters) {
  double x1 = 2.3;
  double y1 = -4.5;

  double x2 = -1.3;
  double y2 = 2.3;

  const Point p1(x1, y1);
  const Point p2(x2, y2);

  LineSegment line(p1, p2);

  EXPECT_EQ(p1, line.a());
  EXPECT_EQ(p2, line.b());
}

TEST_F(LineSegmentTest, Normal) {
  double x1 = 1;
  double y1 = -1;

  double x2 = -1;
  double y2 = -3;

  const Point p1(x1, y1);
  const Point p2(x2, y2);

  LineSegment line(p1, p2);

  Vector n(1, -1);
  n.Normalize();

  EXPECT_EQ(n, line.Normal());
}

TEST_F(LineSegmentTest, Length) {
  const Point a(2.3, -1.3);
  const Point b(3.3, 5.3);

  LineSegment line1(a, b);
  LineSegment line2(a, a);

  EXPECT_NEAR(line1.Length(), 6.67532770731, 1e-10);
  EXPECT_NEAR(line2.Length(), 0, 1e-10);
}

TEST_F(LineSegmentTest, Translation) {
  const Point a(2.3, -1.3);
  const Point b(3.3, 5.3);

  const Point c(3.3, 0.7);
  const Point d(4.3, 7.3);

  Vector v(1, 2);

  LineSegment line(a, b);
  line.Translate(v);

  EXPECT_EQ(line.a_, c);
  EXPECT_EQ(line.b_, d);
}

TEST_F(LineSegmentTest, Rotation) {
  const Point a(-2, 1);
  const Point b(2, 1);

  const Point c(0, -1);
  const Point d(0, 3);

  LineSegment line(a, b);
  line.Rotate(Radians::PI / 2);

  EXPECT_EQ(line.a_, c);
  EXPECT_EQ(line.b_, d);

  line.Rotate(Radians::PI / 2);

  EXPECT_EQ(line.a_, b);
  EXPECT_EQ(line.b_, a);
}

TEST_F(LineSegmentTest, EqualOperator) {
  const Point a(-2, 0);
  const Point b(2, 0);

  const Point c(0, -2);
  const Point d(0, 2);

  LineSegment line1(a, b);
  LineSegment line2(c, d);
  LineSegment line3(b, a);
  LineSegment line4(d, c);

  EXPECT_TRUE(line1 == line1);
  EXPECT_TRUE(line2 == line2);
  EXPECT_FALSE(line1 == line2);
  EXPECT_FALSE(line1 == line3);
  EXPECT_FALSE(line2 == line4);
}

TEST_F(LineSegmentTest, NotEqualOperator) {
  const Point a(-2, 0);
  const Point b(2, 0);

  const Point c(0, -2);
  const Point d(0, 2);

  LineSegment line1(a, b);
  LineSegment line2(c, d);
  LineSegment line3(b, a);
  LineSegment line4(d, c);

  EXPECT_FALSE(line1 != line1);
  EXPECT_FALSE(line2 != line2);
  EXPECT_TRUE(line1 != line2);
  EXPECT_TRUE(line1 != line3);
  EXPECT_TRUE(line2 != line4);
}

}  // namespace gl2d
