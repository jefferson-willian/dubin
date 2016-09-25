#ifndef DUBIN_INCLUDE_DUBIN_H_
#define DUBIN_INCLUDE_DUBIN_H_

#include "gl2d/include/arc.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/vector.h"

namespace dubin {

class Path {
 private:
  gl2d::Arc out_;
  gl2d::Arc in_;
  gl2d::Arc mid_arc_;
  gl2d::LineSegment mid_line_;

  bool is_csc_;

 public:
  Path() = default;
  ~Path() = default;

  double Length() const;

  bool CSC() const { return is_csc_; }
  bool CCC() const { return !is_csc_; }

  static std::vector<Path> GetAllPaths(const gl2d::Point& a,
      const gl2d::Vector& d1, const gl2d::Point& b, const gl2d::Vector& d2,
      double curvature);

  static Path* ShortestPath(const gl2d::Point& a, const gl2d::Vector& d1,
      const gl2d::Point& b, const gl2d::Vector& d2, double curvature);
};

}  // namespace dubin

#endif  // DUBIN_INCLUDE_DUBIN_H_
