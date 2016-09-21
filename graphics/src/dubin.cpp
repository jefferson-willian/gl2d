#include "graphics/include/dubin.h"

#include "gl2d/include/circle.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/point.h"
#include "gl2d/include/arc.h"
#include "gl2d/include/radians.h"
#include "gl2d/include/vector.h"
#include "gl2d/include/tangent.h"

namespace dubin {

namespace {

std::pair<gl2d::Circle, gl2d::Circle> TangentCircles(const gl2d::Point& orig,
    gl2d::Vector dir, double radius) {
  dir.Normalize();
  dir *= radius;

  dir.Rotate(gl2d::Radians::PI / 2);
  gl2d::Circle c1(orig + dir.Point(), radius);

  dir.Rotate(-gl2d::Radians::PI);
  gl2d::Circle c2(orig + dir.Point(), radius);

  return {c1, c2};
}

gl2d::Arc GetArc(const gl2d::Circle& c, const gl2d::Point& p1, const gl2d::Point& p2) {
  return gl2d::Arc(c, gl2d::Vector(c.Center(), p1).Angle(),
      gl2d::Vector(c.Center(), p2).Angle());
}

}  // namespace

std::vector<Path> Path::GetAllPaths(const gl2d::Point& a, const gl2d::Vector& d1,
    const gl2d::Point& b, const gl2d::Vector& d2, double curvature) {
  std::vector<Path> paths;

  auto ca = TangentCircles(a, d1, curvature);
  auto cb = TangentCircles(b, d2, curvature);

  std::vector<gl2d::LineSegment> lines;

  lines = gl2d::Tangent(ca.second, cb.second);
  if (lines.size() >= 1) {
    const gl2d::LineSegment& line = gl2d::LineSegment(lines[0]);

    Path p;
    p.line_segment_ = line;
    p.out_ = gl2d::Arc(ca.second, line.a(), a);
    p.in_ = gl2d::Arc(cb.second, b, line.b());
    p.is_csc_ = true;

    paths.emplace_back(p);
  }

  return paths;
}

}  // namespace dubin
