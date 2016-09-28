#ifndef GL2D_INCLUDE_ARC_H_
#define GL2D_INCLUDE_ARC_H_

#include "gl2d/circle.h"
#include "gl2d/radians.h"

#ifdef _UNIT_TESTING_
#include "gtest/gtest.h"
#endif

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

#ifdef _UNIT_TESTING_
  // Friend test classes.
  friend class ArcTest;
#endif
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_ARC_H_
