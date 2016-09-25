#ifndef GL2D_INCLUDE_ARC_H_
#define GL2D_INCLUDE_ARC_H_

#include "gl2d/include/circle.h"
#include "gl2d/include/radians.h"

#include "gtest/gtest.h"

namespace gl2d {

class Arc : public Circle {
 protected:
  Radians start_;
  Radians end_;

 public:
  using Circle::Circle;

  explicit Arc(const Circle& circle, Radians start, Radians end);
  explicit Arc(const Circle& circle, const Point& p1, const Point& p2);
  Arc() = default;
  ~Arc() = default;

  void RadiansStart(const Radians& start) { start_ = start; }
  void RadiansEnd(const Radians& end) { end_ = end; }

  double Length() const;

  void Complement();

  // Friend test classes.
  friend class ArcTest;
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_ARC_H_
