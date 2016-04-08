#include "gl2d/include/radians.h"

namespace gl2d {

Radians::Radians(double radians) : radians_(radians) {}

Radians& Radians::operator*=(double k) {
  radians_ *= k;
  return *this;
}

Radians& Radians::operator+=(double k) {
  radians_ += k;
  return *this;
}

Radians& Radians::operator-=(double k) {
  radians_ -= k;
  return *this;
}

Radians& Radians::operator/=(double k) {
  radians_ /= k;
  return *this;
}

Radians& Radians::operator*=(const Radians& r) {
  radians_ *= r.Get();
  return *this;
}

Radians& Radians::operator+=(const Radians& r) {
  radians_ += r.Get();
  return *this;
}

Radians& Radians::operator-=(const Radians& r) {
  radians_ -= r.Get();
  return *this;
}

Radians& Radians::operator/=(const Radians& r) {
  radians_ /= r.Get();
  return *this;
}

Radians operator*(const Radians& r1, const Radians& r2) {
  Radians t = r1;
  t *= r2;
  return t;
}

Radians operator*(const Radians& radians, double k) {
  Radians t = radians;
  t *= k;
  return t;
}

Radians operator*(double k, const Radians& radians) {
  Radians t = radians;
  t *= k;
  return t;
}

Radians operator+(const Radians& r1, const Radians& r2) {
  Radians t = r1;
  t += r2;
  return t;
}

Radians operator+(const Radians& radians) {
  return radians;
}

Radians operator+(const Radians& radians, double k) {
  Radians t = radians;
  t += k;
  return t;
}

Radians operator+(double k, const Radians& radians) {
  Radians t = radians;
  t += k;
  return t;
}

Radians operator-(const Radians& r1, const Radians& r2) {
  Radians t = r1;
  t -= r2;
  return t;
}

Radians operator-(const Radians& radians) {
  Radians t = radians;
  t.radians_ = -t.radians_;
  return t;
}

Radians operator-(const Radians& radians, double k) {
  Radians t = radians;
  t -= k;
  return t;
}

Radians operator-(double k, const Radians& radians) {
  Radians t = -radians;
  t += k;
  return t;
}

Radians operator/(const Radians& r1, const Radians& r2) {
  Radians t = r1;
  t /= r2;
  return t;
}

Radians operator/(const Radians& radians, double k) {
  Radians t = radians;
  t /= k;
  return t;
}

Radians operator/(double k, const Radians& radians) {
  Radians t(k);
  t /= radians;
  return t;
}

Radians& Radians::operator=(double k) {
  radians_ = k;
  return *this;
}

bool Radians::operator==(const Radians& radians) const {
  return util::cmpD(radians_, radians.Get()) == 0;
}

bool Radians::operator!=(const Radians& radians) const {
  return !(*this == radians);
}

double Radians::Cos(const Radians& radians) {
  return cos(radians.Get());
}

double Radians::Sin(const Radians& radians) {
  return sin(radians.Get());
}

const Radians Radians::PI(3.14159265358979323846264338327950288419716939937510);
const Radians Radians::TWOPI(2 * Radians::PI);

}  // namespace gl2d
