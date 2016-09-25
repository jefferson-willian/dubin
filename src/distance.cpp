#include "gl2d/include/distance.h"

#include <cmath>
#include "gl2d/include/point.h"

namespace gl2d {

double Distance(const Point& a, const Point& b) {
  return sqrt(pow(a.x() - b.x(), 2) + pow(a.y() - b.y(), 2));
}

}  // namespace gl2d
