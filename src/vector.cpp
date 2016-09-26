#include "gl2d/vector.h"

#include <cmath>

#include "gl2d/point.h"
#include "gl2d/radians.h"
#include "gl2d/util.h"

namespace gl2d {

Vector::Vector(double x, double y) : dest_(x, y) {}
Vector::Vector(const ::gl2d::Point& dest) : dest_(dest) {}
Vector::Vector(const ::gl2d::Point& orig, const ::gl2d::Point& dest) :
    dest_(dest - orig) {}

double Vector::x() const {
    return dest_.x();
}

void Vector::x(double x) {
    dest_.x(x);
}

void Vector::y(double y) {
    dest_.y(y);
}

double Vector::y() const {
    return dest_.y();
}

const ::gl2d::Point& Vector::Point() const {
    return dest_;
}

double Vector::Magnitude() const {
  return sqrt(dest_.x() * dest_.x() + dest_.y() * dest_.y());
}

void Vector::Magnitude(double magnitude) {
  this->Normalize();
  *this *= magnitude;
}

Vector& Vector::Normalize() {
  *this /= Magnitude();
  return *this;
}

Radians Vector::Angle() const {
  Radians angle = Radians::Acos(dest_.x() / Magnitude());
  if (util::cmpD(dest_.y(), 0) < 0)
    angle = 2 * Radians::PI - angle;
  return angle;
}

Vector& Vector::Rotate(const Radians& angle) {
  double x = dest_.x() * Radians::Cos(angle) - dest_.y() * Radians::Sin(angle);
  double y = dest_.x() * Radians::Sin(angle) + dest_.y() * Radians::Cos(angle);
  dest_.x(x);
  dest_.y(y);
  return *this;
}

Vector& Vector::operator+=(const Vector& v) {
  dest_ += v.dest_;
  return *this;
}

Vector& Vector::operator-=(const Vector& v) {
  dest_ -= v.dest_;
  return *this;
}

Vector& Vector::operator*=(double k) {
  dest_ *= k;
  return *this;
}

Vector& Vector::operator/=(double k) {
  dest_ /= k;
  return *this;
}

Vector operator+(const Vector& v) {
  return v;
}

Vector operator+(const Vector& v, const Vector& w) {
  Vector t = v;
  t += w;
  return t;
}

Vector operator-(const Vector& v, const Vector& w) {
  Vector t = v;
  t -= w;
  return t;
}

Vector operator-(const Vector& v) {
  return Vector(-v.x(), -v.y());
}

Vector operator*(const Vector& v, double k) {
  Vector t = v;
  t *= k;
  return t;
}

Vector operator*(double k, const Vector& v) {
  Vector t = v;
  t *= k;
  return t;
}

Vector operator/(const Vector& v, double k) {
  Vector t = v;
  t /= k;
  return t;
}

bool Vector::operator==(const Vector& v) const {
  return dest_ == v.dest_;
}

bool Vector::operator!=(const Vector& v) const {
  return dest_ != v.dest_;
}

const Vector Vector::i = Vector(1, 0);
const Vector Vector::j = Vector(0, 1);

}  // namespace gl2d
