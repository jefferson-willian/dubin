#include "dubin/include/dubin.h"

#include "gl2d/include/arc.h"
#include "gl2d/include/circle.h"
#include "gl2d/include/distance.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/point.h"
#include "gl2d/include/radians.h"
#include "gl2d/include/tangent.h"
#include "gl2d/include/vector.h"

namespace dubin {

namespace {

std::pair<gl2d::Circle, gl2d::Circle> TangentCircles(const gl2d::Point& orig,
    gl2d::Vector dir, double radius) {
  dir.Magnitude(radius);

  dir.Rotate(gl2d::Radians::PI / 2);
  gl2d::Circle c1(orig + dir.Point(), radius);

  dir.Rotate(-gl2d::Radians::PI);
  gl2d::Circle c2(orig + dir.Point(), radius);

  return {c1, c2};
}

}  // namespace

std::vector<Path> Path::GetAllPaths(const gl2d::Point& a,
    const gl2d::Vector& d1, const gl2d::Point& b, const gl2d::Vector& d2,
    double curvature) {
  std::vector<Path> paths;

  if (a == b && d1 == d2)
    return paths;

  auto ca = TangentCircles(a, d1, curvature);
  auto cb = TangentCircles(b, d2, curvature);

  // Curves permutation. RR, LL, RL, LR.
  int ca_i[] = {1, 0, 1, 0};
  int cb_i[] = {1, 0, 0, 1};

  // Get CSC.
  for (int i = 0; i < 4; ++i) {
    const gl2d::Circle& cai = ca_i[i] == 0 ? ca.first : ca.second;
    const gl2d::Circle& cbi = cb_i[i] == 0 ? cb.first : cb.second;

    const std::vector<gl2d::LineSegment>& lines = gl2d::Tangent(cai, cbi);

    if (lines.size() > i) {
      Path p;
      p.mid_line_ = lines[i];
      p.out_ = gl2d::Arc(cai, a, lines[i].a());
      p.in_  = gl2d::Arc(cbi, lines[i].b(), b);
      p.is_csc_ = true;

      if (ca_i[i] == 1) p.out_.Complement();
      if (cb_i[i] == 1) p.in_.Complement();

      paths.emplace_back(p);
    }
  }

  for (int i = 0; i < 2; ++i) {
    auto c1 = i == 0 ? ca.first : ca.second;
    auto c2 = i == 0 ? cb.first : cb.second;

    if (c1 == c2)
      continue;

    double dist = gl2d::Distance(c1.Center(), c2.Center());

    if (gl2d::util::cmpD(dist, c1.Radius() * 4) > 0)
      continue;

    gl2d::Vector v(c1.Center(), c2.Center());
    v.Magnitude(2 * c1.Radius());
    auto rotation = gl2d::Radians::Acos(dist / 2 / v.Magnitude());
    v.Rotate(i == 0 ? rotation : -rotation);

    gl2d::Circle c3(c1.Center() + v.Point(), c1.Radius());

    Path p_;
    p_.out_ = gl2d::Arc(c1, a, c3.Center());
    p_.in_ = gl2d::Arc(c2, c3.Center(), b);
    p_.mid_arc_ = gl2d::Arc(c3, c2.Center(), c1.Center());
    p_.is_csc_ = false;

    if (i == 1) {
      p_.out_.Complement();
      p_.in_.Complement();
      p_.mid_arc_.Complement();
    }

    paths.emplace_back(p_);
  }

  return paths;
}

Path* Path::ShortestPath(const gl2d::Point& a, const gl2d::Vector& d1,
    const gl2d::Point& b, const gl2d::Vector& d2, double curvature) {
  const std::vector<Path>& paths = GetAllPaths(a, d1, b, d2, curvature);

  if (paths.empty())
    return nullptr;

  int id = 0;
  for (int i = 1; i < paths.size(); ++i) {
    const Path& path = paths[i];
    if (gl2d::util::cmpD(path.Length(), paths[id].Length()) < 0)
      id = i;
  }

  return new Path(paths[id]);
}

double Path::Length() const {
  return out_.Length() + in_.Length() + (is_csc_ ? mid_line_.Length()
    : mid_arc_.Length());
}

}  // namespace dubin
