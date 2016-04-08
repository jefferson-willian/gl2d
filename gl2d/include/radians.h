#ifndef GL2D_INCLUDE_RADIANS_H_
#define GL2D_INCLUDE_RADIANS_H_

#include "gtest/gtest.h"

namespace gl2d {

class Radians {
 protected:
  double radians_;

 public:
  explicit Radians();
  explicit Radians(double radians);
  ~Radians() = default;

  operator double() const { return radians_; }

  Radians& operator=(double k);

  static const Radians PI;
  static const Radians TWOPI;

  FRIEND_TEST(RadiansTest, Constructor);
  FRIEND_TEST(RadiansTest, DoubleAssignment);
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_RADIANS_H_
