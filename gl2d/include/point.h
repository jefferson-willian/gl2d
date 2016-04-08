#ifndef GL2D_INCLUDE_POINT_H_
#define GL2D_INCLUDE_POINT_H_

#include "gtest/gtest.h"

namespace gl2d {

// Forward declaration.
class Vector;

class Point {
 protected:
  // x-coordinate.
  double x_;
  // y-coordinate.
  double y_;

 public:
  Point(double x, double y);
  Point() = default;
  ~Point() = default;

  // Get x-coordinate.
  double x() const;

  // Set x-coordinate.
  void x(double x);

  // Get y-coordinate.
  double y() const;

  // Set y-coordinate.
  void y(double y);

  // Translate transformation.
  Point& Translate(const Vector& v);

  // Mathematical operators.
  Point& operator+=(const Point& p);
  Point& operator-=(const Point& p);
  Point& operator*=(double k);
  Point& operator/=(double k);

  friend Point operator+(const Point& p, const Point& q);
  friend Point operator+(const Point& p);
  friend Point operator-(const Point& p, const Point& q);
  friend Point operator-(const Point& p);
  friend Point operator*(const Point& p, double k);
  friend Point operator*(double k, const Point& p);
  friend Point operator/(const Point& p, double k);

  bool operator==(const Point& p) const;
  bool operator!=(const Point& p) const;

  // Friend test classes.
  friend class PointTest;
  FRIEND_TEST(PointTest, Constructor);
  FRIEND_TEST(PointTest, Getters);
  FRIEND_TEST(PointTest, Setters);
  FRIEND_TEST(PointTest, Translation);
  FRIEND_TEST(PointTest, Addition);
  FRIEND_TEST(PointTest, Subtraction);
  FRIEND_TEST(PointTest, Multiplication);
  FRIEND_TEST(PointTest, Division);
  FRIEND_TEST(PointTest, OperatorEqual);
  FRIEND_TEST(PointTest, OperatorNotEqual);
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_POINT_H_

