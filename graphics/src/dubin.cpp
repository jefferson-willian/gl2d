#include "graphics/include/dubin.h"

#include "gl2d/include/circle.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/point.h"
#include "gl2d/include/arc.h"
#include "gl2d/include/radians.h"
#include "gl2d/include/distance.h"
#include "gl2d/include/vector.h"
#include "gl2d/include/tangent.h"

#include <vector>

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

  // Curves permutation. RR, LL, RR, RL, LR.
  int ca_i[] = {1, 0, 1, 0};
  int cb_i[] = {1, 0, 0, 1};

  // Get CSC.
  for (int i = 0; i < 4; ++i) {
    const gl2d::Circle& cai = ca_i[i] == 0 ? ca.first : ca.second;
    const gl2d::Circle& cbi = cb_i[i] == 0 ? cb.first : cb.second;

    lines = gl2d::Tangent(cai, cbi);

    if (lines.size() > i) {
      const gl2d::LineSegment& line = gl2d::LineSegment(lines[i]);

      const gl2d::Point& p1 = ca_i[i] == 0 ? a : line.a();
      const gl2d::Point& p2 = ca_i[i] == 0 ? line.a() : a;
      const gl2d::Point& p3 = cb_i[i] == 0 ? line.b() : b;
      const gl2d::Point& p4 = cb_i[i] == 0 ? b : line.b();

      Path p;
      p.line_segment_ = line;
      p.out_ = gl2d::Arc(cai, p1, p2);
      p.in_  = gl2d::Arc(cbi, p3, p4);
      p.is_csc_ = true;

      paths.emplace_back(p);
    }
  }

  /*
  auto c1 = ca.first;
  auto c2 = cb.first;

  gl2d::Point cent = c1.Center();
  gl2d::Vector v(c1.Center(), c2.Center());
  v.Normalize();
  v *= 2 * c1.Radius();
  v.Rotate(gl2d::Radians::Acos(gl2d::Distance(c1.Center(), c2.Center()) /
        c1.Radius() / 4));
  cent.Translate(v);
  gl2d::Circle c3(cent, c1.Radius());


  gl2d::Arc rad3(c3, gl2d::Vector(c3.Center(), c1.Center()).Angle(),
      gl2d::Vector(c3.Center(), c2.Center()).Angle());
      */

  return paths;
}

Path* Path::ShortestPath(const gl2d::Point& a, const gl2d::Vector& d1,
    const gl2d::Point& b, const gl2d::Vector& d2, double curvature) {
  const std::vector<Path>& paths = GetAllPaths(a, d1, b, d2, curvature);

  if (paths.empty())
    return nullptr;

  int id = 0;
  double best = paths[0].Length();
  for (int i = 1; i < paths.size(); ++i) {
    const Path& path = paths[i];
    if (gl2d::util::cmpD(path.Length(), best) < 0) {
      id = i;
      best = path.Length();
    }
  }

  return new Path(paths[id]);
}

}  // namespace dubin
