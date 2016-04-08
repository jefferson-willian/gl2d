#ifndef GL2D_INCLUDE_VECTOR_H_
#define GL2D_INCLUDE_VECTOR_H_

#include <cmath>
#include <istream>
#include <ostream>

#include "gl2d/include/radians.h"
#include "gl2d/include/point.h"
#include "gtest/gtest.h"

namespace gl2d {

class Vector {
 protected:
  // Vector's destination point. The vector's origin is always (0,0).
  ::gl2d::Point dest_;

 public:
  // Creates a vector with destination point (x,y).
  explicit Vector(double x, double y);
  // Creates a vector with destination point |dest|.
  explicit Vector(const ::gl2d::Point& dest);
  // Creates a vector that has origin in |orig| and destination in |dest|, then
  // the vector is translated to the origin (0,0).
  explicit Vector(const ::gl2d::Point& orig, const ::gl2d::Point& dest);
  ~Vector() = default;

  // Get x-coordinate.
  double x() const;

  // Set x-coordinate.
  void x(double x);

  // Get y-coordinate.
  double y() const;

  // Set y-coordinate.
  void y(double y);

  // Get the vector destination point.
  const ::gl2d::Point& Point() const;

  // Set the vector destination point.
  void Point(const ::gl2d::Point& dest);

  // Get the vector magnitude.
  double Magnitude() const;

  // Normalize vector.
  Vector& Normalize();

  Radians Angle() const;

  Vector& Rotate(const Radians& angle);

  Vector& operator+=(const Vector& v);
  Vector& operator-=(const Vector& v);
  Vector& operator*=(double k);
  Vector& operator/=(double k);

  friend Vector operator+(const Vector& v, const Vector& w);
  friend Vector operator-(const Vector& v, const Vector& w);
  friend Vector operator-(const Vector& v);
  friend Vector operator*(const Vector& v, double k);
  friend Vector operator*(double k, const Vector& v);
  friend Vector operator/(const Vector& v, double k);

  bool operator==(const Vector& v) const;
  bool operator!=(const Vector& v) const;

  // Canonical vectors.
  static const Vector i;
  static const Vector j;

  FRIEND_TEST(VectorTest, Constructor);
  FRIEND_TEST(VectorTest, Setters);
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_VECTOR_H_
