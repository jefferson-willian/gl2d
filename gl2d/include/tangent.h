#ifndef GL2D_INCLUDE_TANGENT_H_
#define GL2D_INCLUDE_TANGENT_H_

#include <vector>

#include "gl2d/include/circle.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/point.h"

namespace gl2d {

std::vector<LineSegment> Tangent(const Point& p, const Circle& c);

}  // namespace gl2d

#endif  // GL2D_INCLUDE_TANGENT_H_
