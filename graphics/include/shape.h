#ifndef GRAPHICS_INCLUDE_SHAPE_H_
#define GRAPHICS_INCLUDE_SHAPE_H_

#include <string>

namespace graphics {

class Shape {
 public:
  Shape() = default;
  virtual ~Shape() = default;

  virtual const std::string Latex(double proportion) const = 0;
};

}  // namespace graphics

#endif  // GRAPHICS_INCLUDE_SHAPE_H_
