#include "gl2d/util.h"

namespace gl2d {
namespace util {

int cmpD(double a, double b) {
  return (a <= b + GL2D_EPS) ?  (a + GL2D_EPS < b) ? -1 : 0 : 1;
}

}  // namespace util
}  // namespace gl2d
