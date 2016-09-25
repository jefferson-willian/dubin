#include "gl2d/include/line.h"

#include "gl2d/include/point.h"
#include "gl2d/include/radians.h"
#include "gl2d/include/vector.h"

namespace gl2d {

Line::Line(const Vector& n, double x, double y) : n_(n), origin_(x, y) {
  n_.Normalize();
}
Line::Line(const Vector& n, const Point& origin) : n_(n), origin_(origin) {
  n_.Normalize();
}

const Vector& Line::Normal() const {
  return n_;
}

void Line::Normal(const Vector& n) {
  n_ = n;
  n_.Normalize();
}

const Point& Line::Origin() const {
  return origin_;
}

void Line::Origin(double x, double y) {
  origin_.x(x);
  origin_.y(y);
}

void Line::Origin(const Point& origin) {
  origin_ = origin;
}

double Line::A() const {
  return n_.x();
}

double Line::B() const {
  return n_.y();
}

double Line::C() const {
  return n_.x() * origin_.x() + n_.y() * origin_.y();
}

Line& Line::Translate(const Vector& v) {
  origin_.Translate(v);
  return *this;
}

Line& Line::Rotate(const Radians& angle) {
  n_.Rotate(angle);
  return *this;
}

bool Line::operator==(const Line& rhs) const {
  return n_ == rhs.n_ && origin_ == rhs.origin_;
}

bool Line::operator!=(const Line& rhs) const {
  return n_ != rhs.n_ || origin_ != rhs.origin_;
}

}  // namespace gl2d
