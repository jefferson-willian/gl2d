#include "gl2d/include/line.h"
#include "gtest/gtest.h"

namespace gl2d {

class LineTest : public ::testing::Test {
};

TEST_F(LineTest, Constructor) {
  double x = 2.3;
  double y = -4.5;

  const Point p(x, y);
  Vector n(3, 3);

  Line line1(n, x, y);
  Line line2(n, p);

  n.Normalize();

  EXPECT_EQ(line1.n_, n);
  EXPECT_EQ(line1.origin_, p);

  EXPECT_EQ(line2.n_, n);
  EXPECT_EQ(line2.origin_, p);
}

TEST_F(LineTest, Getters) {
  double x = 2.3;
  double y = -4.5;

  const Point p(x, y);
  Vector n(3, 3);

  Line line(n, x, y);

  n.Normalize();

  EXPECT_EQ(line.Normal(), n);
  EXPECT_EQ(line.Origin(), p);
}

TEST_F(LineTest, Setters) {
  double x = 2.3;
  double y = -4.5;

  const Point p(x, y);
  Vector n(3, 3);

  Line line1(Vector::i, 0, 0);
  Line line2(Vector::i, 0, 0);

  line1.Normal(n);
  line1.Origin(p);

  line2.Normal(n);
  line2.Origin(x, y);

  n.Normalize();

  EXPECT_EQ(line1.n_, n);
  EXPECT_EQ(line1.origin_, p);

  EXPECT_EQ(line2.n_, n);
  EXPECT_EQ(line2.origin_, p);
}

TEST_F(LineTest, LineEquation) {
  double x = 2.3;
  double y = -4.5;

  const Point p(x, y);
  Vector n(3, 3);

  const Line line1(n, x, y);
  const Line line2(Vector::i, x, y);
  const Line line3(Vector::j, x, y);

  n.Normalize();

  EXPECT_DOUBLE_EQ(line1.A(), n.x());
  EXPECT_DOUBLE_EQ(line1.B(), n.y());
  EXPECT_DOUBLE_EQ(line1.C(), n.x() * x + n.y() * y);

  EXPECT_DOUBLE_EQ(line2.A(), 1);
  EXPECT_DOUBLE_EQ(line2.B(), 0);
  EXPECT_DOUBLE_EQ(line2.C(), x);

  EXPECT_DOUBLE_EQ(line3.A(), 0);
  EXPECT_DOUBLE_EQ(line3.B(), 1);
  EXPECT_DOUBLE_EQ(line3.C(), y);
}

TEST_F(LineTest, Translation) {
  Vector n(3, 3);
  Vector v(-2, 5);

  double x = 2.3;
  double y = -4.5;

  Point p(x, y);

  Line line1(n, x, y);

  p.Translate(v);

  Line line2(n, p);

  line1.Translate(v);

  EXPECT_EQ(line1, line2);
}

TEST_F(LineTest, Rotation) {
  double x = 2.3;
  double y = -4.5;

  Point p(x, y);

  Line line1(Vector::i, x, y);

  Line line2(Vector::j, p);

  line1.Rotate(Radians::PI / 2);

  EXPECT_EQ(line1, line2);
}

TEST_F(LineTest, EqualOperator) {
  Point origin1(2.3, -4.5);
  Point origin2(0, 0);

  Vector n1(1, 1);
  Vector n2(2, 1);

  Line line1(n1, origin1);
  Line line2(n1, origin2);
  Line line3(n2, origin1);

  EXPECT_TRUE(line1 == line1);
  EXPECT_FALSE(line1 == line2);
  EXPECT_FALSE(line1 == line3);

  Line line4(Vector::i, 0, 0);
  Line line5(-Vector::i, 0, 0);

  EXPECT_FALSE(line4 == line5);
}

TEST_F(LineTest, NotEqualOperator) {
  Point origin1(2.3, -4.5);
  Point origin2(0, 0);

  Vector n1(1, 1);
  Vector n2(2, 1);

  Line line1(n1, origin1);
  Line line2(n1, origin2);
  Line line3(n2, origin1);

  EXPECT_FALSE(line1 != line1);
  EXPECT_TRUE(line1 != line2);
  EXPECT_TRUE(line1 != line3);

  Line line4(Vector::i, 0, 0);
  Line line5(-Vector::i, 0, 0);

  EXPECT_TRUE(line4 != line5);
}

}  // namespace gl2d
