#ifndef GL2D_INCLUDE_RADIANS_H_
#define GL2D_INCLUDE_RADIANS_H_

#include "gtest/gtest.h"

#include "gl2d/include/util.h"

namespace gl2d {

class Radians {
 protected:
  // Radians value (-2PI, 2PI).
  double radians_;

 public:
  // Create a |radians| radians.
  explicit Radians(double radians);
  Radians() = default;
  ~Radians() = default;

  // Normalize to [-2pi, 2pi].
  Radians& Normalize();

  // Mathematical operators.
  Radians& operator*=(double k);
  Radians& operator+=(double k);
  Radians& operator-=(double k);
  Radians& operator/=(double k);

  Radians& operator*=(const Radians& r);
  Radians& operator+=(const Radians& r);
  Radians& operator-=(const Radians& r);
  Radians& operator/=(const Radians& r);

  friend Radians operator*(const Radians& r1, const Radians& r2);
  friend Radians operator*(const Radians& radians, double k);
  friend Radians operator*(double k, const Radians& radians);
  friend Radians operator+(const Radians& r1, const Radians& r2);
  friend Radians operator+(const Radians& radians);
  friend Radians operator+(const Radians& radians, double k);
  friend Radians operator+(double k, const Radians& radians);
  friend Radians operator-(const Radians& r1, const Radians& r2);
  friend Radians operator-(const Radians& radians);
  friend Radians operator-(const Radians& radians, double k);
  friend Radians operator-(double k, const Radians& radians);
  friend Radians operator/(const Radians& r1, const Radians& r2);
  friend Radians operator/(const Radians& radians, double k);
  friend Radians operator/(double k, const Radians& radians);

  Radians& operator=(double k);

  bool operator==(const Radians& radians) const;
  bool operator!=(const Radians& radians) const;

  // Trigonometric Functions.
  static double Cos(const Radians& radians);
  static double Sin(const Radians& radians);

  static Radians Acos(double value);
  static Radians Asin(double value);

  // Pi and 2Pi static constant values.
  static const Radians PI;
  static const Radians TWOPI;

  // Friend test classes.
  friend class RadiansTest;
  FRIEND_TEST(RadiansTest, Constructor);
  FRIEND_TEST(RadiansTest, Setters);
  FRIEND_TEST(RadiansTest, Normalize);
  FRIEND_TEST(RadiansTest, Addition);
  FRIEND_TEST(RadiansTest, Subtraction);
  FRIEND_TEST(RadiansTest, Product);
  FRIEND_TEST(RadiansTest, Division);
  FRIEND_TEST(RadiansTest, DoubleAssignment);
  FRIEND_TEST(RadiansTest, ArcCosine);
  FRIEND_TEST(RadiansTest, ArcSine);
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_RADIANS_H_
