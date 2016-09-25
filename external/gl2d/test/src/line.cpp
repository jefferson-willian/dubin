#include "gl2d/include/line.h"
#include "gtest/gtest.h"

namespace gl2d {

class LineTest : public ::testing::Test {
 protected:
  Line line0_;
  Line line1_;
  Line line2_;
  Line line3_;

  virtual void SetUp() {
    line0_.n_ = Vector(3, 3).Normalize();
    line0_.origin_ = Point(2.3, -4.5);

    line1_.n_ = Vector(3, 3).Normalize();
    line1_.origin_ = Point(5.2, 1.5);

    line2_.n_ = Vector(0, 1).Normalize();
    line2_.origin_ = Point(2.3, -4.5);

    line3_.n_ = Vector(1, 0).Normalize();
    line3_.origin_ = Point(2.3, -4.5);
  }

  virtual void ExpectEqual(const Line& line1, const Line& line2) {
    EXPECT_EQ(line1.n_, line2.n_);
    EXPECT_EQ(line1.origin_, line2.origin_);
  }

  virtual void AssertAssignment(Line* line1, const Line& line2) {
    ASSERT_FALSE(line1 == nullptr);
    line1->n_ = line2.n_;
    line1->origin_ = line2.origin_;
    ASSERT_EQ(line1->n_, line2.n_);
    ASSERT_EQ(line1->origin_, line2.origin_);
  }
};

TEST_F(LineTest, Constructor) {
  Line line1(Vector(1, 1), 2.3, -4.5);
  Line line2(Vector(1, 1), Point(2.3, -4.5));

  ExpectEqual(line1, line0_);
  ExpectEqual(line2, line0_);
}

TEST_F(LineTest, Getters) {
  EXPECT_EQ(line0_.Normal(), Vector(3, 3).Normalize());
  EXPECT_EQ(line0_.Origin(), Point(2.3, -4.5));
}

TEST_F(LineTest, Setters) {
  Line line1;
  Line line2;
  Line line3;

  AssertAssignment(&line1, line0_);
  AssertAssignment(&line2, line0_);
  AssertAssignment(&line3, line0_);

  line1.Origin(Point(5.2, 1.5));
  ExpectEqual(line1, line1_);

  line2.Origin(5.2, 1.5);
  ExpectEqual(line2, line1_);

  line3.Normal(Vector(0, 3));
  ExpectEqual(line3, line2_);
}

TEST_F(LineTest, LineEquation) {
  EXPECT_NEAR(line1_.A(), 0.70710678118, 1e-10);
  EXPECT_NEAR(line1_.B(), 0.70710678118, 1e-10);
  EXPECT_NEAR(line1_.C(), 4.73761543395, 1e-10);

  EXPECT_NEAR(line2_.A(), 0, 1e-10);
  EXPECT_NEAR(line2_.B(), 1, 1e-10);
  EXPECT_NEAR(line2_.C(), -4.5, 1e-10);

  EXPECT_NEAR(line3_.A(), 1, 1e-10);
  EXPECT_NEAR(line3_.B(), 0, 1e-10);
  EXPECT_NEAR(line3_.C(), 2.3, 1e-10);
}

TEST_F(LineTest, Translation) {
  line0_.Translate(Vector(2.9, 6));
  ExpectEqual(line0_, line1_);
}

TEST_F(LineTest, Rotation) {
  Line line1;
  Line line2;

  AssertAssignment(&line1, line0_);
  AssertAssignment(&line2, line0_);

  line1.Rotate(Radians::PI / 4);
  ExpectEqual(line1, line2_);

  line2.Rotate(2 * Radians::PI);
  ExpectEqual(line2, line0_);
}

TEST_F(LineTest, EqualOperator) {
  EXPECT_TRUE(line0_ == line0_);
  EXPECT_FALSE(line0_ == line1_);
  EXPECT_FALSE(line0_ == line2_);
}

TEST_F(LineTest, NotEqualOperator) {
  EXPECT_FALSE(line0_ != line0_);
  EXPECT_TRUE(line0_ != line1_);
  EXPECT_TRUE(line0_ != line2_);
}

}  // namespace gl2d
