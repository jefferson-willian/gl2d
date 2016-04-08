#ifndef GL2D_INCLUDE_RADIANS_H_
#define GL2D_INCLUDE_RADIANS_H_

#include "gtest/gtest.h"

namespace gl2d {

class Radians {
 protected:
  // Radians value (-2PI, 2PI).
  double radians_;

 public:
  // Create a 0 radian.
  Radians();
  // Create a |radians| radians.
  explicit Radians(double radians);
  ~Radians() = default;

  // Operator conversion.
  operator double() const;

  // Mathematical operators.
  Radians& operator=(double k);

  // Pi and 2Pi static constant values.
  static const Radians PI;
  static const Radians TWOPI;

  FRIEND_TEST(RadiansTest, Constructor);
  FRIEND_TEST(RadiansTest, DoubleAssignment);
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_RADIANS_H_
