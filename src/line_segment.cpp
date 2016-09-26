#include "gl2d/line_segment.h"

#include "gl2d/distance.h"
#include "gl2d/point.h"
#include "gl2d/radians.h"
#include "gl2d/vector.h"

namespace gl2d {

LineSegment::LineSegment(const Point& a, const Point& b) : a_(a), b_(b) {}

const Point& LineSegment::a() const {
  return a_;
}

void LineSegment::a(double x, double y) {
  a_.x(x);
  a_.y(y);
}

void LineSegment::a(const Point& a) {
  a_ = a;
}

const Point& LineSegment::b() const {
  return b_;
}

void LineSegment::b(double x, double y) {
  b_.x(x);
  b_.y(y);
}

void LineSegment::b(const Point& b) {
  b_ = b;
}

const Vector LineSegment::Normal() const {
  Vector v(a_, b_);
  v.Rotate(Radians::PI / 2).Normalize();
  return v;
}

double LineSegment::Length() const {
  return Distance(a_, b_);
}

LineSegment& LineSegment::Translate(const Vector& v) {
  a_.Translate(v);
  b_.Translate(v);
  return *this;
}

LineSegment& LineSegment::Rotate(const Radians& angle) {
  Point center = (a_ + b_) / 2;

  Vector va(center, a_);
  Vector vb(center, b_);

  va.Rotate(angle);
  vb.Rotate(angle);

  va += Vector(center);
  vb += Vector(center);

  a_ = va.Point();
  b_ = vb.Point();

  return *this;
}

bool LineSegment::operator==(const LineSegment& rhs) const {
  return a_ == rhs.a_ && b_ == rhs.b_;
}

bool LineSegment::operator!=(const LineSegment& rhs) const {
  return a_ != rhs.a_ || b_ != rhs.b_;
}

}  // namespace gl2d

