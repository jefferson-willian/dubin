#include "gl2d/include/circle.h"
#include "gl2d/include/location.h"
#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class CircleTest : public ::testing::Test {
 protected:
  Circle circle0_;
  Circle circle1_;
  Circle circle2_;

  virtual void SetUp() {
    circle0_.center_ = Point(2.3, -4.5);
    circle0_.radius_ = 2.5;

    circle1_.center_ = Point(5.2, 1.5);
    circle1_.radius_ = 2.5;

    circle2_.center_ = Point(2.3, -4.5);
    circle2_.radius_ = 1;
  }

  virtual void ExpectEqual(const Circle& c1, const Circle& c2) {
    EXPECT_EQ(c1.center_, c2.center_);
    EXPECT_NEAR(c1.radius_, c2.radius_, 1e-10);
  }

  virtual void AssertAssignment(Circle* c1, const Circle& c2) {
    ASSERT_FALSE(c1 == nullptr);
    c1->center_ = c2.center_;
    c1->radius_ = c2.radius_;
    ASSERT_EQ(c1->center_, c2.center_);
    ASSERT_NEAR(c1->radius_, c2.radius_, 1e-10);
  }
};

TEST_F(CircleTest, Constructor) {
  Circle c1(2.3, -4.5, 2.5);
  Circle c2(Point(2.3, -4.5), 2.5);

  ExpectEqual(c1, circle0_);
  ExpectEqual(c2, circle0_);
}

TEST_F(CircleTest, Getters) {
  EXPECT_EQ(circle0_.Center(), Point(2.3, -4.5));
  EXPECT_NEAR(circle0_.Radius(), 2.5, 1e-10);
}

TEST_F(CircleTest, Setters) {
  Circle c1;
  Circle c2;
  Circle c3;

  AssertAssignment(&c1, circle0_);
  AssertAssignment(&c2, circle0_);
  AssertAssignment(&c3, circle0_);

  c1.Center(5.2, 1.5);
  ExpectEqual(c1, circle1_);

  c2.Center(Point(5.2, 1.5));
  ExpectEqual(c2, circle1_);

  c3.Radius(1);
  ExpectEqual(c3, circle2_);
}

TEST_F(CircleTest, Translation) {
  circle0_.Translate(Vector(2.9, 6.0));

  ExpectEqual(circle0_, circle1_);
}

TEST_F(CircleTest, Location)  {
  EXPECT_EQ(circle0_.Location(Point(2.3, -4.5)), Location::INSIDE);
  EXPECT_EQ(circle0_.Location(Point(3, -4)), Location::INSIDE);
  EXPECT_EQ(circle0_.Location(Point(2.3, -2)), Location::BORDER);
  EXPECT_EQ(circle0_.Location(Point(0, 0)), Location::OUTSIDE);
}

TEST_F(CircleTest, OperatorEqual) {
  EXPECT_TRUE(circle0_ == circle0_);
  EXPECT_FALSE(circle0_ == circle1_);
  EXPECT_FALSE(circle0_ == circle2_);
  EXPECT_FALSE(circle1_ == circle2_);
}

TEST_F(CircleTest, OperatorNotEqual) {
  EXPECT_FALSE(circle0_ != circle0_);
  EXPECT_TRUE(circle0_ != circle1_);
  EXPECT_TRUE(circle0_ != circle2_);
  EXPECT_TRUE(circle1_ != circle2_);
}

}  // namespace gl2d
