#include "gl2d/point.h"

#include "gl2d/util.h"
#include "gl2d/vector.h"

namespace gl2d {

Point::Point(double x, double y) : x_(x), y_(y) {}

double Point::x() const {
  return x_;
}

void Point::x(double x) {
  x_ = x;
}

double Point::y() const {
  return y_;
}

void Point::y(double y) {
  y_ = y;
}

Point& Point::Translate(const Vector& v) {
  x_ += v.x();
  y_ += v.y();
  return *this;
}

Point& Point::operator+=(const Point& p) {
  x_ += p.x_;
  y_ += p.y_;
  return *this;
}

Point& Point::operator-=(const Point& p) {
  x_ -= p.x_;
  y_ -= p.y_;
  return *this;
}

Point& Point::operator*=(double k) {
  x_ *= k;
  y_ *= k;
  return *this;
}

Point& Point::operator/=(double k) {
  x_ /= k;
  y_ /= k;
  return *this;
}

Point operator+(const Point& p, const Point& q) {
  Point t = p;
  t += q;
  return t;
}

Point operator+(const Point& p) {
  return p;
}

Point operator-(const Point& p, const Point& q) {
  Point t = p;
  t -= q;
  return t;
}

Point operator-(const Point& p) {
  return Point(-p.x_, -p.y_);
}

Point operator*(const Point& p, double k) {
  Point t = p;
  t *= k;
  return t;
}

Point operator*(double k, const Point& p) {
  Point t = p;
  t *= k;
  return t;
}

Point operator/(const Point& p, double k) {
  Point t = p;
  t /= k;
  return t;
}

bool Point::operator==(const Point& p) const {
  return util::cmpD(x_, p.x_) == 0 && util::cmpD(y_, p.y_) == 0;
}

bool Point::operator!=(const Point& p) const {
  return util::cmpD(x_, p.x_) != 0 || util::cmpD(y_, p.y_) != 0;
}

}  // namespace gl2d
