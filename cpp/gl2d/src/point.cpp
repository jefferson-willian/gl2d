#include "gl2d/include/point.h"

#include "gl2d/include/util.h"

namespace gl2d {

Point::Point(double x, double y) : x_(x), y_(y) {}

double Point::x() const {
  return x_;
}

void Point::x(double x) {
  x_ = x;
}

double Point::y() const {
  return y_;
}

void Point::y(double y) {
  y_ = y;
}

bool Point::operator==(const Point& p) const {
  return util::cmpD(x_, p.x()) == 0 && util::cmpD(y_, p.y()) == 0;
}

bool Point::operator!=(const Point& p) const {
  return !(*this == p);
}

}  // namespace gl2d
