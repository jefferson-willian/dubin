#ifndef GL2D_INCLUDE_RADIANS_H_
#define GL2D_INCLUDE_RADIANS_H_

#include "gtest/gtest.h"

#include "gl2d/util.h"

namespace gl2d {

class Radians {
 protected:
  // Radians value (-2PI, 2PI).
  double radians_;

 public:
  // Create a |radians| radians.
  explicit Radians(double radians);
  Radians() = default;
  ~Radians() = default;

  // Normalize to [-2pi, 2pi].
  Radians& Normalize();

  // Trigonometric Functions.
  static double Cos(const Radians& radians);
  static double Sin(const Radians& radians);

  static Radians Acos(double value);
  static Radians Asin(double value);

  double val() const { return radians_; }
  double degree() const { return radians_ / 3.141592653589 * 180.; }

  // Mathematical operators.
  Radians& operator*=(double k);
  Radians& operator/=(double k);

  //Radians& operator*=(const Radians& r);
  Radians& operator+=(const Radians& r);
  Radians& operator-=(const Radians& r);
  //Radians& operator/=(const Radians& r);

  friend Radians operator*(const Radians& radians, double k);
  friend Radians operator*(double k, const Radians& radians);
  friend Radians operator+(const Radians& r1, const Radians& r2);
  friend Radians operator+(const Radians& radians);
  friend Radians operator-(const Radians& r1, const Radians& r2);
  friend Radians operator-(const Radians& radians);
  friend Radians operator/(const Radians& radians, double k);

  Radians& operator=(double k);

  bool operator==(const Radians& radians) const;
  bool operator!=(const Radians& radians) const;

  // Pi and 2Pi static constant values.
  static const Radians PI;
  static const Radians TWOPI;

  // Friend test classes.
  friend class RadiansTest;
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_RADIANS_H_
