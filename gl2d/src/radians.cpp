#include "gl2d/include/radians.h"

namespace gl2d {

Radians::Radians() : radians_(0) {}

Radians::Radians(double radians) : radians_(radians) {}

Radians& Radians::operator=(double k) {
  radians_ = k;
  return *this;
}

const Radians Radians::PI(3.14159265358979323846);
const Radians Radians::TWOPI(2 * Radians::PI);

}  // namespace gl2d
