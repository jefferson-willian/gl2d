#ifndef GL2D_INCLUDE_CIRCLE_H_
#define GL2D_INCLUDE_CIRCLE_H_

#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class Circle {
 protected:
  // Center location.
  Point center_;
  // Radius.
  double radius_;

 public:
  explicit Circle(double x, double y, double r);
  explicit Circle(const Point& center, double r);
  ~Circle() = default;

  // Get the circle center location.
  const Point& Center() const;

  // Set the circle center location.
  void Center(double x, double y);
  void Center(const Point& center);

  // Get the circle radius.
  double Radius() const;

  // Set circle radius.
  void Radius(double r);

  // Translate the circle center location.
  Circle& Translate(const Vector& v);

  // Mathematical operators.
  bool operator==(const Circle& rhs) const;
  bool operator!=(const Circle& rhs) const;

  FRIEND_TEST(CircleTest, Constructor);
  FRIEND_TEST(CircleTest, Setters);
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_CIRCLE_H_
