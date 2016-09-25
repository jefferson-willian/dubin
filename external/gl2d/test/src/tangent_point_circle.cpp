#include "gl2d/include/tangent.h"

#include <vector>

#include "gl2d/include/circle.h"
#include "gl2d/include/line_segment.h"
#include "gl2d/include/point.h"
#include "gtest/gtest.h"

namespace gl2d {

class TangentPointCircleTest : public ::testing::Test {
};

TEST_F(TangentPointCircleTest, PointBorderCircle) {
  const Point p(0, 1);
  const Circle c(0, 0, 1);

  const std::vector<LineSegment>& lines = Tangent(p, c);

  EXPECT_EQ(lines.size(), 0);
}

TEST_F(TangentPointCircleTest, PointInsideCircle) {
  const Point p(0, 0.5);
  const Circle c(0, 0, 1);

  const std::vector<LineSegment>& lines = Tangent(p, c);

  EXPECT_EQ(lines.size(), 0);
}

TEST_F(TangentPointCircleTest, PointOutsideCircleAndZeroRadius) {
  const Point p(0, 0);
  const Circle c(2, 0, 0);

  const LineSegment line1(p, Point(2, 0));
  const LineSegment line2(p, Point(2, 0));

  const std::vector<LineSegment>& lines = Tangent(p, c);

  ASSERT_EQ(lines.size(), 2);
  EXPECT_EQ(lines[0], line1);
  EXPECT_EQ(lines[1], line2);
}

TEST_F(TangentPointCircleTest, PointOutsideCircle_FirstQuadrant) {
  const Point p(0, 0);
  const Circle c(5, 3, 1);

  const LineSegment line1(p, Point(4.34606800178, 3.75655333037));
  const LineSegment line2(p, Point(5.35981435117, 2.06697608139));

  const std::vector<LineSegment>& lines = Tangent(p, c);

  ASSERT_EQ(lines.size(), 2);
  EXPECT_EQ(lines[0], line1);
  EXPECT_EQ(lines[1], line2);
}

TEST_F(TangentPointCircleTest, PointOutsideCircle_SecondQuadrant) {
  const Point p(0, 0);
  const Circle c(-5, 3, 1);

  const LineSegment line1(p, Point(-5.35981435117, 2.06697608139));
  const LineSegment line2(p, Point(-4.34606800178, 3.75655333037));

  const std::vector<LineSegment>& lines = Tangent(p, c);

  ASSERT_EQ(lines.size(), 2);
  EXPECT_EQ(lines[0], line1);
  EXPECT_EQ(lines[1], line2);
}

TEST_F(TangentPointCircleTest, PointOutsideCircle_ThirdQuadrant) {
  const Point p(0, 0);
  const Circle c(-5, -3, 1);

  const LineSegment line1(p, Point(-4.34606800178, -3.75655333037));
  const LineSegment line2(p, Point(-5.35981435117, -2.06697608139));

  const std::vector<LineSegment>& lines = Tangent(p, c);

  ASSERT_EQ(lines.size(), 2);
  EXPECT_EQ(lines[0], line1);
  EXPECT_EQ(lines[1], line2);
}

TEST_F(TangentPointCircleTest, PointOutsideCircle_FourthQuadrant) {
  const Point p(0, 0);
  const Circle c(5, -3, 1);

  const LineSegment line1(p, Point(5.35981435117, -2.06697608139));
  const LineSegment line2(p, Point(4.34606800178, -3.75655333037));

  const std::vector<LineSegment>& lines = Tangent(p, c);

  ASSERT_EQ(lines.size(), 2);
  EXPECT_EQ(lines[0], line1);
  EXPECT_EQ(lines[1], line2);
}

}  // namespace gl2d
