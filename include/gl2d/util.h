#ifndef GL2D_INCLUDE_UTIL_H_
#define GL2D_INCLUDE_UTIL_H_

namespace gl2d {
namespace util {

#define EPS 1e-10

// Compare two doubles with 1e-10 decimal precision.
int cmpD(double a, double b);

}  // namespace util
}  // namespace gl2d

#endif  // GL2D_INCLUDE_UTIL_H_

