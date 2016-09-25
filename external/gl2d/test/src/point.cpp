#include "gl2d/include/point.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class PointTest : public ::testing::Test {
 protected:
  Point p0_;
  Point p1_;
  Point p2_;
  Point p3_;
  Point p4_;
  Point p5_;
  Point p6_;

  virtual void SetUp() {
    p0_.x_ = 2.3;
    p0_.y_ = -4.5;

    p1_.x_ = 2.3;
    p1_.y_ = 5.5;

    p2_.x_ = 1.3;
    p2_.y_ = -4.5;

    p3_.x_ = 1.3;
    p3_.y_ = 5.5;

    p4_.x_ = 3.6;
    p4_.y_ = 1;

    p5_.x_ = -2.3;
    p5_.y_ = 4.5;

    p6_.x_ = 2.3 * 3.5;
    p6_.y_ = -4.5 * 3.5;
  }

  virtual void ExpectEqual(const Point& p1, const Point& p2) {
    EXPECT_NEAR(p1.x_, p2.x_, 1e-10);
    EXPECT_NEAR(p1.y_, p2.y_, 1e-10);
  }

  virtual void AssertAssignment(Point* p1, const Point& p2) {
    ASSERT_FALSE(p1 == nullptr);
    p1->x_ = p2.x_;
    p1->y_ = p2.y_;
    ASSERT_NEAR(p1->x_, p2.x_, 1e-10);
    ASSERT_NEAR(p1->y_, p2.y_, 1e-10);
  }
};

TEST_F(PointTest, Constructor) {
  const Point p1(2.3, -4.5);

  ExpectEqual(p1, p0_);
}

TEST_F(PointTest, Getters) {
  EXPECT_NEAR(p0_.x(), 2.3, 1e-10);
  EXPECT_NEAR(p0_.y(), -4.5, 1e-10);
}

TEST_F(PointTest, Setters) {
  Point p1;
  Point p2;

  AssertAssignment(&p1, p0_);
  AssertAssignment(&p2, p0_);

  p1.y(5.5);
  ExpectEqual(p1, p1_);

  p2.x(1.3);
  ExpectEqual(p2, p2_);
}

TEST_F(PointTest, Translation) {
  Vector v(-1, 10);

  ASSERT_NEAR(v.x(), -1, 1e-10);
  ASSERT_NEAR(v.y(), 10, 1e-10);

  p0_.Translate(v);

  ExpectEqual(p0_, p3_);
}

TEST_F(PointTest, Addition) {
  Point p1;
  Point p2;
  Point p3;

  AssertAssignment(&p1, p0_ + p3_);
  AssertAssignment(&p2, +p4_);
  AssertAssignment(&p3, p0_);
  p3 += p3_;

  ExpectEqual(p1, p4_);
  ExpectEqual(p2, p4_);
  ExpectEqual(p3, p4_);
}

TEST_F(PointTest, Subtraction) {
  Point p1;
  Point p2;
  Point p3;

  AssertAssignment(&p1, p4_ - p3_);
  AssertAssignment(&p2, -p0_);
  AssertAssignment(&p3, p4_);
  p3 -= p3_;

  ExpectEqual(p1, p0_);
  ExpectEqual(p2, p5_);
  ExpectEqual(p3, p0_);
}

TEST_F(PointTest, Multiplication) {
  Point p1;
  Point p2;
  Point p3;

  AssertAssignment(&p1, p0_ * 3.5);
  AssertAssignment(&p2, 3.5 * p0_);
  AssertAssignment(&p3, p0_);
  p3 *= 3.5;

  ExpectEqual(p1, p6_);
  ExpectEqual(p2, p6_);
  ExpectEqual(p3, p6_);
}

TEST_F(PointTest, Division) {
  Point p1;
  Point p2;

  AssertAssignment(&p1, p6_ / 3.5);
  AssertAssignment(&p2, p6_);
  p2 /= 3.5;

  ExpectEqual(p1, p0_);
  ExpectEqual(p2, p0_);
}

TEST_F(PointTest, OperatorEqual) {
  EXPECT_TRUE(p0_ == p0_);
  EXPECT_FALSE(p0_ == p1_);
  EXPECT_FALSE(p0_ == p2_);
}

TEST_F(PointTest, OperatorNotEqual) {
  EXPECT_FALSE(p0_ != p0_);
  EXPECT_TRUE(p0_ != p1_);
  EXPECT_TRUE(p0_ != p2_);
}

}  // namespace gl2d
