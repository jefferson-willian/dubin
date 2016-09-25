#include "gl2d/include/util.h"

namespace gl2d {
namespace util {

int cmpD(double a, double b) {
  return (a <= b + EPS) ?  (a + EPS < b) ? -1 : 0 : 1;
}

}  // namespace util
}  // namespace gl2d
