#include <iostream>
#include <fstream>
#include <vector>

#include "graphics/include/circle.h"
#include "graphics/include/line_segment.h"
#include "graphics/include/point.h"
#include "graphics/include/image.h"
#include "graphics/include/arc.h"

#include "gl2d/include/tangent.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gl2d/include/radians.h"

std::pair<graphics::Circle, graphics::Circle> TangentCircles(const gl2d::LineSegment& line, double radius) {
  gl2d::Vector v(line.a(), line.b());
  v.Normalize();
  v *= radius;

  v.Rotate(gl2d::Radians::PI / 2);
  graphics::Circle c1(line.a() + v.Point(), radius);
  v.Rotate(gl2d::Radians::PI);
  graphics::Circle c2(line.a() + v.Point(), radius);

  return {c1, c2};
}

void NormalizeLine(gl2d::LineSegment* line) {
  gl2d::Vector v(line->a(), line->b());
  v.Normalize();
  line->b(line->a() + v.Point());
}

graphics::LineSegment TangentLL(const gl2d::Circle& c1, const gl2d::Circle& c2) {
  return gl2d::Tangent(c1, c2).second;
}

graphics::LineSegment TangentRR(const gl2d::Circle& c1, const gl2d::Circle& c2) {
  return gl2d::Tangent(c1, c2).first;
}

graphics::Arc GetArc(const gl2d::Circle& c, const gl2d::Point& p1, const gl2d::Point& p2) {
  graphics::Arc arc(c.Center(), c.Radius());

  gl2d::Vector v1(c.Center(), p1);
  arc.RadiansStart(v1.Angle());
  gl2d::Vector v2(c.Center(), p2);
  arc.RadiansEnd(v2.Angle());

  return arc;
}

int main(int argc, char** argv) {
  graphics::Image img(10);

  graphics::LineSegment w1(gl2d::Point(0, 0), gl2d::Point(1, 1));
  graphics::LineSegment w2(gl2d::Point(4, -2), gl2d::Point(-1, 1));

  w1.SetArrow();
  w1.SetColor("blue");
  w2.SetArrow();
  w2.SetColor("blue");

  NormalizeLine(&w1);
  NormalizeLine(&w2);

  // Start DUBINS
  auto outCircles = TangentCircles(w1, 1);
  auto inCircles = TangentCircles(w2, 1);

  auto tline1 = TangentLL(outCircles.first, inCircles.first);
  img.Add(&tline1);

  auto tline2 = TangentRR(outCircles.second, inCircles.second);
  img.Add(&tline2);

  auto arc1 = GetArc(outCircles.first, w1.a(), tline1.a());
  auto arc2 = GetArc(inCircles.first, tline1.b(), w2.a());

  auto arc3 = GetArc(outCircles.second, tline2.a(), w1.a());
  auto arc4 = GetArc(inCircles.second, w2.a(), tline2.b());

  img.Add(&arc1);
  img.Add(&arc2);
  img.Add(&arc3);
  img.Add(&arc4);

  img.Add(&w1);
  img.Add(&w2);

  std::cout << img.Latex() << '\n';

  return 0;
}
