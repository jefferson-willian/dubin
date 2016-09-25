#ifndef GL2D_INCLUDE_LINE_H_
#define GL2D_INCLUDE_LINE_H_

#include "gl2d/include/point.h"
#include "gl2d/include/radians.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class Line {
 protected:
  // Normal vector.
  Vector n_;
  // Vector origin point.
  Point origin_;

 public:
  explicit Line(const Vector& n, double x, double y);
  explicit Line(const Vector& n, const Point& origin);
  Line() = default;
  ~Line() = default;

  // Get normal vector.
  const Vector& Normal() const;

  // Set the normal of the vector v.
  void Normal(const Vector& v);

  // Get vector origin point.
  const Point& Origin() const;

  // Set vector origin point.
  void Origin(double x, double y);
  void Origin(const Point& origin);

  // Get the constants of the line equation. Ax + By = C.
  double A() const;
  double B() const;
  double C() const;

  // Translate the line.
  Line& Translate(const Vector& v);

  // Rotate the line.
  Line& Rotate(const Radians& angle);

  // Mathematical operators.
  bool operator==(const Line& rhs) const;
  bool operator!=(const Line& rhs) const;

  friend class LineTest;
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_LINE_H_
