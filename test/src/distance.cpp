#include "gl2d/include/distance.h"
#include "gl2d/include/point.h"
#include "gtest/gtest.h"

namespace gl2d {

class DistanceTest : public ::testing::Test {
};

TEST_F(DistanceTest, PointDistance) {
  const Point a(2.3, -1.3);
  const Point b(3.3, 5.3);

  EXPECT_NEAR(Distance(a, b), 6.67532770731, 1e-10);
  EXPECT_NEAR(Distance(a, a), 0, 1e-10);
}

}  // namespace gl2d
