#include "gl2d/include/line_segment.h"
#include "gtest/gtest.h"

namespace gl2d {

class LineSegmentTest : public ::testing::Test {
 protected:
  LineSegment line0_;
  LineSegment line1_;
  LineSegment line2_;
  LineSegment line3_;
  LineSegment line4_;
  LineSegment line5_;

  virtual void SetUp() {
    line0_.a_ = Point(2.3, -4.5);
    line0_.b_ = Point(-1.3, 2.3);

    line1_.a_ = Point(1.3, 2.5);
    line1_.b_ = Point(-1.3, 2.3);

    line2_.a_ = Point(2.3, -4.5);
    line2_.b_ = Point(1.3, 2.5);

    line3_.a_ = Point(1.3, 2.5);
    line3_.b_ = Point(-2.3, 9.3);

    line4_.a_ = Point(-2, 1);
    line4_.b_ = Point(2, 1);

    line5_.a_ = Point(0, -1);
    line5_.b_ = Point(0, 3);
  }

  virtual void ExpectEqual(const LineSegment& line1, const LineSegment& line2) {
    EXPECT_EQ(line1.a_, line2.a_);
    EXPECT_EQ(line1.b_, line2.b_);
  }

  virtual void AssertAssignment(LineSegment* line1, const LineSegment& line2) {
    ASSERT_FALSE(line1 == nullptr);
    line1->a_ = line2.a_;
    line1->b_ = line2.b_;
    ASSERT_EQ(line1->a_, line2.a_);
    ASSERT_EQ(line1->b_, line2.b_);
  }
};

TEST_F(LineSegmentTest, Constructor) {
  LineSegment line1(Point(2.3, -4.5), Point(-1.3, 2.3));

  ExpectEqual(line1, line0_);
}

TEST_F(LineSegmentTest, Setters) {
  LineSegment line1;
  LineSegment line2;
  LineSegment line3;
  LineSegment line4;

  AssertAssignment(&line1, line0_);
  AssertAssignment(&line2, line0_);
  AssertAssignment(&line3, line0_);
  AssertAssignment(&line4, line0_);

  line1.a(1.3, 2.5);
  line2.a(Point(1.3, 2.5));

  ExpectEqual(line1, line1_);
  ExpectEqual(line2, line1_);

  line3.b(1.3, 2.5);
  line4.b(Point(1.3, 2.5));

  ExpectEqual(line3, line2_);
  ExpectEqual(line4, line2_);
}

TEST_F(LineSegmentTest, Getters) {
  EXPECT_EQ(line0_.a(), Point(2.3, -4.5));
  EXPECT_EQ(line0_.b(), Point(-1.3, 2.3));
}

TEST_F(LineSegmentTest, Normal) {
  Vector v(-0.883787916347, -0.467887720419);

  EXPECT_EQ(v, line0_.Normal());
}

TEST_F(LineSegmentTest, Length) {
  EXPECT_NEAR(line0_.Length(), 7.69415362467, 1e-10);
}

TEST_F(LineSegmentTest, Translation) {
  line0_.Translate(Vector(-1, 7));

  ExpectEqual(line0_, line3_);
}

TEST_F(LineSegmentTest, Rotation) {
  line4_.Rotate(Radians::PI / 2);

  ExpectEqual(line4_, line5_);
}

TEST_F(LineSegmentTest, EqualOperator) {
  EXPECT_TRUE(line0_ == line0_);
  EXPECT_FALSE(line0_ == line1_);
  EXPECT_FALSE(line0_ == line2_);
}

TEST_F(LineSegmentTest, NotEqualOperator) {
  EXPECT_FALSE(line0_ != line0_);
  EXPECT_TRUE(line0_ != line1_);
  EXPECT_TRUE(line0_ != line2_);
}

}  // namespace gl2d
