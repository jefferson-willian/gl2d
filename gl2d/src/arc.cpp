#include "gl2d/include/arc.h"

#include "gl2d/include/point.h"

namespace gl2d {

Arc::Arc(const Circle& circle, Radians start, Radians end) : Circle(circle),
  start_(start), end_(end) {}
Arc::Arc(const Circle& circle, const Point& p1, const Point& p2) :
  Circle(circle), start_(Vector(circle.Center(), p1).Angle()),
  end_(Vector(circle.Center(), p2).Angle()) {}

}  // namespace gl2d
