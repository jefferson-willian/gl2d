#include "gl2d/include/arc.h"

#include "gl2d/include/point.h"

namespace gl2d {

Arc::Arc(double x, double y, double r) : Circle(x, y, r) {}
Arc::Arc(const Point& center, double r) : Circle(center, r) {}

}  // namespace gl2d
