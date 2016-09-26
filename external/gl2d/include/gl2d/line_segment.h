#ifndef GL2D_INCLUDE_LINE_SEGMENT_H_
#define GL2D_INCLUDE_LINE_SEGMENT_H_

#include "gl2d/point.h"
#include "gl2d/radians.h"
#include "gl2d/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class LineSegment {
 protected:
  // Beginning point.
  Point a_;
  // Ending point.
  Point b_;

 public:
  explicit LineSegment(const Point& a, const Point& b);
  LineSegment() = default;
  ~LineSegment() = default;

  // Get the starting point.
  const Point& a() const;

  // Set the beginning point.
  void a(double x, double y);
  void a(const Point& a);

  // Get the ending point.
  const Point& b() const;

  // Set the ending point.
  void b(double x, double y);
  void b(const Point& b);

  // Get the line segment normal.
  const Vector Normal() const;

  // Get the line segment length.
  double Length() const;

  // Translate the line segment.
  LineSegment& Translate(const Vector& v);

  // Rotate the line segment.
  LineSegment& Rotate(const Radians& angle);

  // Operators.
  bool operator==(const LineSegment& rhs) const;
  bool operator!=(const LineSegment& rhs) const;

  friend class LineSegmentTest;
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_LINE_SEGMENT_H_
