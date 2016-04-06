#include "gl2d/include/util.h"

namespace util {

#define EPS 1e-10

int cmpD(double a, double b) {
  return (a <= b + EPS) ?  (a + EPS < b) ? -1 : 0 : 1;
}

}  // namespace util
