#include <iostream>
#include <fstream>
#include <vector>

#include "graphics/include/circle.h"
#include "graphics/include/line_segment.h"
#include "graphics/include/point.h"
#include "graphics/include/image.h"
#include "gl2d/include/tangent.h"
#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"

int main(int argc, char** argv) {
  graphics::Image img(10);

  graphics::LineSegment w1(gl2d::Point(0, 0), gl2d::Point(1, 1));
  graphics::LineSegment w2(gl2d::Point(4, -2), gl2d::Point(-1, 1));
  w1.SetArrow();
  w2.SetArrow();

  gl2d::Vector v1(w1.a(), w1.b());
  gl2d::Vector v2(w2.a(), w2.b());
  v1.Normalize();
  v2.Normalize();

  w1.b(w1.a() + v1.Point());
  w2.b(w2.a() + v2.Point());

  graphics::Circle c1(w1.a(), 1);
  graphics::Circle c2(w1.a(), 1);
  graphics::Circle c3(w2.a(), 1);
  graphics::Circle c4(w2.a(), 1);

  v1.Rotate(gl2d::Radians::PI / 2);
  c1.Translate(v1);
  v1.Rotate(gl2d::Radians::PI);
  c2.Translate(v1);

  v2.Rotate(gl2d::Radians::PI / 2);
  c3.Translate(v2);
  v2.Rotate(gl2d::Radians::PI);
  c4.Translate(v2);

  img.Add(&w1);
  img.Add(&w2);
  img.Add(&c1);
  img.Add(&c2);
  img.Add(&c3);
  img.Add(&c4);

  auto lines = gl2d::Tangent(c1, c3);
  img.Add(new graphics::LineSegment(lines.second));

  std::cout << img.Latex() << '\n';

  return 0;
}
