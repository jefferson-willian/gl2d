#include "gl2d/include/vector.h"

#include <cmath>

#include "gl2d/include/point.h"

namespace gl2d {

Vector::Vector(double x, double y) : dest_(x, y) {}
Vector::Vector(const ::gl2d::Point& dest) : dest_(dest) {}
//Vector::Vector(const ::gl2d::Point& orig, const ::gl2d::Point& dest) : dest_(dest - orig) {}

const ::gl2d::Point& Vector::Point() const {
    return dest_;
}

void Vector::Point(const ::gl2d::Point& dest) {
    dest_ = dest;
}

double Vector::x() const {
    return dest_.x();
}

void Vector::x(double x) {
    dest_.x(x);
}

void Vector::y(double y) {
    dest_.y(y);
}

double Vector::y() const {
    return dest_.y();
}

double Vector::Magnitude() const {
  return sqrt(dest_.x() * dest_.x() + dest_.y() * dest_.y());
}

Vector& Vector::Normalize() {
  *this /= Magnitude();
  return *this;
}

Vector& Vector::operator+=(const Vector& v) {
  dest_ += v.Point();
  return *this;
}

Vector& Vector::operator-=(const Vector& v) {
  dest_ -= v.Point();
  return *this;
}

Vector& Vector::operator*=(double k) {
  dest_ *= k;
  return *this;
}

Vector& Vector::operator/=(double k) {
  dest_ /= k;
  return *this;
}

bool Vector::operator==(const Vector& v) const {
  return dest_ == v.Point();
}

bool Vector::operator!=(const Vector& v) const {
  return !(*this == v);
}

const Vector Vector::i = Vector(1, 0);
const Vector Vector::j = Vector(0, 1);

}  // namespace gl2d

