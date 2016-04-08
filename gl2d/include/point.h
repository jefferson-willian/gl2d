#ifndef GL2D_INCLUDE_POINT_H_
#define GL2D_INCLUDE_POINT_H_

#include "gtest/gtest.h"

namespace gl2d {


class Point {
 protected:
  // x-coordinate.
  double x_;
  // y-coordinate.
  double y_;

 public:
  explicit Point(double x, double y);
  ~Point() = default;

  // Get x-coordinate.
  double x() const;

  // Set x-coordinate.
  void x(double x);

  // Get y-coordinate.
  double y() const;

  // Set y-coordinate.
  void y(double y);

  // Mathematical operators.
  Point& operator+=(const Point& p);
  Point& operator-=(const Point& p);
  Point& operator*=(double k);
  Point& operator/=(double k);

  friend Point operator+(const Point& p, const Point& q);
  friend Point operator-(const Point& p, const Point& q);
  friend Point operator-(const Point& p);
  friend Point operator*(const Point& p, double k);
  friend Point operator*(double k, const Point& p);
  friend Point operator/(const Point& p, double k);

  bool operator==(const Point& p) const;
  bool operator!=(const Point& p) const;

  FRIEND_TEST(PointTest, Constructor);
  FRIEND_TEST(PointTest, Setters);
};


}  // namespace gl2d

#endif  // GL2D_INCLUDE_POINT_H_

