#include "gl2d/include/tangent.h"

#include <vector>

#include "gl2d/include/circle.h"
#include "gl2d/include/distance.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/point.h"

namespace gl2d {

std::vector<LineSegment> Tangent(const Point& p, const Circle& c) {
  std::vector<LineSegment> lines;

  if (c.Location(p) == Location::OUTSIDE) {
    double dist    = Distance(p, c.Center());
    Radians angle  = Radians::Asin(c.Radius() / dist);
    double length  = Radians::Cos(angle) * dist;

    // First intersection point.
    Vector v1(p, c.Center());
    v1.Rotate(angle).Normalize();
    v1 *= length;
    v1 += Vector(p);

    // Second intersection point.
    Vector v2(p, c.Center());
    v2.Rotate(-angle).Normalize();
    v2 *= length;
    v2 += Vector(p);

    lines.emplace_back(LineSegment(p, v1.Point()));
    lines.emplace_back(LineSegment(p, v2.Point()));
  }

  return lines;
}

}  // namespace gl2d
