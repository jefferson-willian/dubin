#include "gl2d/include/arc.h"

#include "gl2d/include/point.h"

namespace gl2d {

Arc::Arc(const Circle& circle, Radians start, Radians end) : Circle(circle),
  start_(start), end_(end) {}
Arc::Arc(const Circle& circle, const Point& p1, const Point& p2) :
  Circle(circle), start_(Vector(circle.Center(), p1).Angle()),
  end_(Vector(circle.Center(), p2).Angle()) {}

double Arc::Length() const {
  Radians l = end_ - start_;
  if (util::cmpD(l.val(), 0) < 0)
    l += Radians::TWOPI;
  return l.val() * radius_;
}

void Arc::Complement() {
  std::swap(start_, end_);
}

}  // namespace gl2d
