#include "gl2d/include/circle.h"

#include "gl2d/include/point.h"
#include "gl2d/include/util.h"
#include "gl2d/include/vector.h"

namespace gl2d {

Circle::Circle(double x, double y, double r) : center_(x, y), radius_(r) {}
Circle::Circle(const Point& center, double r) : center_(center), radius_(r) {}

const Point& Circle::Center() const {
  return center_;
}

void Circle::Center(double x, double y) {
  center_.x(x);
  center_.y(y);
}

void Circle::Center(const Point& center) {
  center_ = center;
}

double Circle::Radius() const {
  return radius_;
}

void Circle::Radius(double radius) {
  radius_ = radius;
}

Circle& Circle::Translate(const Vector& v) {
  center_.Translate(v);
  return *this;
}

bool Circle::operator==(const Circle& rhs) const {
  return center_ == rhs.center_ && util::cmpD(radius_, rhs.radius_) == 0;
}

bool Circle::operator!=(const Circle& rhs) const {
  return center_ != rhs.center_ || util::cmpD(radius_, rhs.radius_) != 0;
}

}  // namespace gl2d
