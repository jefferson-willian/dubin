#ifndef GL2D_INCLUDE_CIRCLE_H_
#define GL2D_INCLUDE_CIRCLE_H_

#include "gl2d/location.h"
#include "gl2d/point.h"
#include "gl2d/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class Circle {
 protected:
  // Center location.
  Point center_;
  // Radius.
  double radius_;

 public:
  explicit Circle(double x, double y, double r);
  explicit Circle(const Point& center, double r);
  Circle() = default;
  ~Circle() = default;

  // Get the circle center location.
  const Point& Center() const;

  // Set the circle center location.
  void Center(double x, double y);
  void Center(const Point& center);

  // Get the circle radius.
  double Radius() const;

  // Set circle radius.
  void Radius(double radius);

  // Translate the circle center location.
  Circle& Translate(const Vector& v);

  // Return the reference location for the point. Possible results are:
  //    - Location::INSIDE
  //    - Location::BORDER
  //    - Location::OUTSIDE
  //    - Location::UNKNOWN (error purposes only).
  ::gl2d::Location Location(const Point& point) const;

  // Mathematical operators.
  bool operator==(const Circle& rhs) const;
  bool operator!=(const Circle& rhs) const;

  // Friend test classes.
  friend class CircleTest;
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_CIRCLE_H_
