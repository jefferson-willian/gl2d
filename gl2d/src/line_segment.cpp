#include "gl2d/include/line_segment.h"

#include "gl2d/include/distance.h"
#include "gl2d/include/point.h"
#include "gl2d/include/radians.h"
#include "gl2d/include/vector.h"

namespace gl2d {

LineSegment::LineSegment(const Point& a, const Point& b) : a_(a), b_(b) {}

const Point& LineSegment::a() const {
  return a_;
}

void LineSegment::a(double x, double y) {
  a_.x(x);
  a_.y(y);
}

void LineSegment::a(const Point& a) {
  a_ = a;
}

const Point& LineSegment::b() const {
  return b_;
}

void LineSegment::b(double x, double y) {
  b_.x(x);
  b_.y(y);
}

void LineSegment::b(const Point& b) {
  b_ = b;
}

const Vector LineSegment::Normal() const {
  Vector v(a_, b_);
  v.Rotate(Radians::PI / 2).Normalize();
  return v;
}

double LineSegment::Length() const {
  return Distance(a_, b_);
}

LineSegment& LineSegment::Translate(const Vector& v) {
  a_.Translate(v);
  b_.Translate(v);
  return *this;
}

LineSegment& LineSegment::Rotate(const Radians& angle) {
  Point center = (a_ + b_) / 2;
  Translate(-Vector(center));
  Vector a(a_);
  Vector b(b_);
  a.Rotate(angle);
  b.Rotate(angle);
  a_ = a.Point();
  b_ = b.Point();
  Translate(Vector(center));
  return *this;
}

bool LineSegment::operator==(const LineSegment& rhs) const {
  return a_ == rhs.a() && b_ == rhs.b();
}

bool LineSegment::operator!=(const LineSegment& rhs) const {
  return !(*this == rhs);
}

}  // namespace gl2d

