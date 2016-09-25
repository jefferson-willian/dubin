#include "gl2d/include/point.h"
#include "gl2d/include/radians.h"
#include "gl2d/include/vector.h"
#include "gtest/gtest.h"

namespace gl2d {

class VectorTest : public ::testing::Test {
 protected:
  Vector vector0_;
  Vector vector1_;
  Vector vector2_;
  Vector vector3_;
  Vector vector4_;
  Vector vector5_;
  Vector vector6_;
  Vector vector7_;
  Vector vector8_;
  Vector vector9_;
  Vector vector10_;
  Vector vector11_;
  Vector vector12_;

  virtual void SetUp() {
    vector0_.dest_ = Point(2.3, -4.5);
    vector1_.dest_ = Point(1.3, 5.5);
    vector2_.dest_ = Point(3, -4);
    vector3_.dest_ = Point(0, 3);
    vector4_.dest_ = Point(-3, 0);
    vector5_.dest_ = Point(0, -3);
    vector6_.dest_ = Point(3, 0);
    vector7_.dest_ = Point(-1, 10);
    vector8_.dest_ = Point(0.6, -0.8);
    vector9_.dest_ = Point(3.6, 1);
    vector10_.dest_ = Point(1, -10);
    vector11_.dest_ = Point(-2.3, 4.5);
    vector12_.dest_ = Point(8.05, -15.75);
  }

  virtual void ExpectEqual(const Vector& v1, const Vector& v2) {
    EXPECT_EQ(v1.dest_, v2.dest_);
  }

  virtual void AssertAssignment(Vector* v1, const Vector& v2) {
    ASSERT_FALSE(v1 == nullptr);
    v1->dest_ = v2.dest_;
    ASSERT_EQ(v1->dest_, v2.dest_);
  }
};

TEST_F(VectorTest, Constructor) {
  const Vector v1(2.3, -4.5);
  const Vector v2(Point(2.3, -4.5));
  const Vector v3(Point(2.3, -4.5), Point(1.3, 5.5));

  ExpectEqual(v1, vector0_);
  ExpectEqual(v2, vector0_);
  ExpectEqual(v3, vector7_);
}

TEST_F(VectorTest, Getters) {
  EXPECT_NEAR(2.3, vector0_.x(), 1e-10);
  EXPECT_NEAR(-4.5, vector0_.y(), 1e-10);
  EXPECT_EQ(Point(2.3, -4.5), vector0_.Point());
}

TEST_F(VectorTest, Setters) {
  Vector v1;
  Vector v2;

  AssertAssignment(&v1, vector2_);
  AssertAssignment(&v2, vector4_);

  v1.y(0);
  v2.x(3);

  ExpectEqual(vector6_, v1);
  ExpectEqual(vector6_, v2);
}

TEST_F(VectorTest, Magnitude) {
  EXPECT_NEAR(vector2_.Magnitude(), 5, 1e-10);
}

TEST_F(VectorTest, Normalize) {
  ExpectEqual(vector2_.Normalize(), vector8_);
}

TEST_F(VectorTest, Angle) {
  EXPECT_EQ(vector3_.Angle(), 1 / 2. * Radians::PI);
  EXPECT_EQ(vector4_.Angle(), 2 / 2. * Radians::PI);
  EXPECT_EQ(vector5_.Angle(), 3 / 2. * Radians::PI);
  EXPECT_EQ(vector6_.Angle(), 0 / 2. * Radians::PI);
}

TEST_F(VectorTest, Rotation) {
  Vector v1;
  Vector v2;
  Vector v3;
  Vector v4;

  AssertAssignment(&v1, vector6_);
  AssertAssignment(&v2, vector6_);
  AssertAssignment(&v3, vector6_);
  AssertAssignment(&v4, vector6_);

  EXPECT_EQ(v1.Rotate(1 / 2. * Radians::PI), vector3_);
  EXPECT_EQ(v2.Rotate(2 / 2. * Radians::PI), vector4_);
  EXPECT_EQ(v3.Rotate(3 / 2. * Radians::PI), vector5_);
  EXPECT_EQ(v4.Rotate(4 / 2. * Radians::PI), vector6_);
}

TEST_F(VectorTest, Addition) {
  Vector v1;
  Vector v2;
  Vector v3;

  AssertAssignment(&v1, vector0_ + vector1_);
  AssertAssignment(&v2, +vector0_);
  AssertAssignment(&v3, vector0_);
  v3 += vector1_;

  ExpectEqual(vector9_, v1);
  ExpectEqual(vector0_, v2);
  ExpectEqual(vector9_, v3);
}

TEST_F(VectorTest, Subtraction) {
  Vector v1;
  Vector v2;
  Vector v3;
  
  AssertAssignment(&v1, vector0_ - vector1_);
  AssertAssignment(&v2, -vector0_);
  AssertAssignment(&v3, vector0_);
  v3 -= vector1_;

  ExpectEqual(vector10_, v1);
  ExpectEqual(vector11_, v2);
  ExpectEqual(vector10_, v3);
}

TEST_F(VectorTest, ScalarProduct) {
  double k = 3.5;

  Vector v1;
  Vector v2;
  Vector v3;

  AssertAssignment(&v1, vector0_ * k);
  AssertAssignment(&v2, k * vector0_);
  AssertAssignment(&v3, vector0_);
  v3 *= k;

  ExpectEqual(vector12_, v1);
  ExpectEqual(vector12_, v2);
  ExpectEqual(vector12_, v3);
}

TEST_F(VectorTest, ScalarDivision) {
  double k = 3.5;

  Vector v1;
  Vector v2;

  AssertAssignment(&v1, vector12_ / k);
  AssertAssignment(&v2, vector12_);
  v2 /= k;

  ExpectEqual(vector0_, v1);
  ExpectEqual(vector0_, v2);
}

TEST_F(VectorTest, EqualOperator) {
  EXPECT_TRUE(vector0_ == vector0_);
  EXPECT_FALSE(vector3_ == vector5_);
  EXPECT_FALSE(vector4_ == vector6_);
}

TEST_F(VectorTest, NotEqualOperator) {
  EXPECT_FALSE(vector0_ != vector0_);
  EXPECT_TRUE(vector3_ != vector5_);
  EXPECT_TRUE(vector4_ != vector6_);
}

TEST_F(VectorTest, Canonical) {
  EXPECT_EQ(Point(1, 0), Vector::i.dest_);
  EXPECT_EQ(Point(0, 1), Vector::j.dest_);
}

}  // namespace gl2d
