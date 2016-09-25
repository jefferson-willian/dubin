#include "gl2d/include/radians.h"

#include <cmath>

namespace gl2d {

namespace {

const double pi_ = 3.14159265358979323846264338327950288419716;
const double twopi_ = 2 * pi_;

double prune(double rad) {
  while (util::cmpD(rad, 0) < 0) rad += twopi_;
  while (util::cmpD(rad, twopi_) > 0) rad -= twopi_;

  return rad;
}

}  // namespace

Radians::Radians(double radians) : radians_(radians) {
  radians_ = prune(radians);
}

Radians& Radians::Normalize() {
  const double twopi = Radians::TWOPI.radians_;

  while (util::cmpD(radians_, -twopi) < 0) radians_ += twopi;
  while (util::cmpD(radians_,  twopi) > 0) radians_ -= twopi;

  return *this;
}

Radians& Radians::operator*=(double k) {
  radians_ = prune(radians_ * k);
  return *this;
}

Radians& Radians::operator/=(double k) {
  radians_ = prune(radians_ / k);
  return *this;
}

Radians& Radians::operator+=(const Radians& r) {
  radians_ = prune(radians_ + r.radians_);
  return *this;
}

Radians& Radians::operator-=(const Radians& r) {
  radians_ = prune(radians_ - r.radians_);
  return *this;
}

Radians operator*(const Radians& radians, double k) {
  Radians t = radians;
  t *= k;
  return t;
}

Radians operator*(double k, const Radians& radians) {
  Radians t = radians;
  t *= k;
  return t;
}

Radians operator+(const Radians& r1, const Radians& r2) {
  Radians t = r1;
  t += r2;
  return t;
}

Radians operator+(const Radians& radians) {
  return radians;
}

Radians operator-(const Radians& r1, const Radians& r2) {
  Radians t = r1;
  t -= r2;
  return t;
}

Radians operator-(const Radians& radians) {
  Radians t = radians;
  t.radians_ = twopi_ - t.radians_;
  return t;
}

Radians operator/(const Radians& radians, double k) {
  Radians t = radians;
  t /= k;
  return t;
}

Radians& Radians::operator=(double k) {
  radians_ = prune(k);
  return *this;
}

bool Radians::operator==(const Radians& radians) const {
  return util::cmpD(radians_, radians.radians_) == 0;
}

bool Radians::operator!=(const Radians& radians) const {
  return !(*this == radians);
}

double Radians::Cos(const Radians& radians) {
  return cos(radians.radians_);
}

double Radians::Sin(const Radians& radians) {
  return sin(radians.radians_);
}

Radians Radians::Acos(double value) {
  if (util::cmpD(value, 1) == 0)
    return Radians(acos(1));
  if (util::cmpD(value, -1) == 0)
    return Radians(acos(-1));
  return Radians(acos(value));
}

Radians Radians::Asin(double value) {
  if (util::cmpD(value, 1) == 0)
    return Radians(asin(1));
  if (util::cmpD(value, -1) == 0)
    return Radians(asin(-1));
  return Radians(asin(value));
}

const Radians Radians::PI(pi_);
const Radians Radians::TWOPI(twopi_);

}  // namespace gl2d
