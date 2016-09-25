#include "gl2d/include/tangent.h"

#include <vector>

#include "gl2d/include/circle.h"
#include "gl2d/include/distance.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/point.h"

namespace gl2d {

std::vector<LineSegment> Tangent(const Point& p, const Circle& c) {
  std::vector<LineSegment> lines;

  if (c.Location(p) == Location::OUTSIDE) {
    double dist    = Distance(p, c.Center());
    Radians angle  = Radians::Asin(c.Radius() / dist);
    double length  = Radians::Cos(angle) * dist;

    // First intersection point.
    Vector v1(p, c.Center());
    v1.Rotate(angle).Normalize();
    v1 *= length;
    v1 += Vector(p);

    // Second intersection point.
    Vector v2(p, c.Center());
    v2.Rotate(-angle).Normalize();
    v2 *= length;
    v2 += Vector(p);

    lines.emplace_back(LineSegment(p, v1.Point()));
    lines.emplace_back(LineSegment(p, v2.Point()));
  }

  return lines;
}

std::vector<LineSegment> Tangent(const Circle& c1, const Circle& c2) {
  std::vector<LineSegment> lines;

  if (c1 == c2)
    return lines;

  // Create two lines from center-to-center in both circles.
  LineSegment l1(c1.Center(), c2.Center());
  LineSegment l2(c1.Center(), c2.Center());

  // Translate in normal direction (both positive and negative) with radius
  // magnitude.
  l1.Translate(l1.Normal() * c1.Radius());
  l2.Translate(-l1.Normal() * c1.Radius());

  lines.emplace_back(l1);
  lines.emplace_back(l2);

  if (util::cmpD(Distance(c1.Center(), c2.Center()), c1.Radius() + c2.Radius()) == 0) {
    LineSegment l3(c1.Center(), c1.Center());
    LineSegment l4(c1.Center(), c1.Center());
    Vector v(c1.Center(), c2.Center());
    v.Normalize();
    v *= c1.Radius();
    l3.Translate(v);
    lines.emplace_back(l3);
  } else if (util::cmpD(Distance(c1.Center(), c2.Center()), c1.Radius() + c2.Radius()) > 0) {
    Radians crossAngle = Radians::Acos(c1.Radius() * 2 / Distance(c1.Center(),
          c2.Center()));

    LineSegment l3, l4;

    Vector v(c1.Center(), c2.Center());
    v.Normalize();
    v *= c1.Radius();

    v.Rotate(crossAngle);
    l3.a(c1.Center() + v.Point());
    v.Rotate(-2 * crossAngle);
    l4.a(c1.Center() + v.Point());

    v = Vector(c2.Center(), c1.Center());
    v.Normalize();
    v *= c2.Radius();

    v.Rotate(crossAngle);
    l3.b(c2.Center() + v.Point());
    v.Rotate(-2 * crossAngle);
    l4.b(c2.Center() + v.Point());

    lines.emplace_back(l3);
    lines.emplace_back(l4);
  }

  return lines;
}

}  // namespace gl2d

