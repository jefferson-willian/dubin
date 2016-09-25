#include "gl2d/include/radians.h"
#include "gtest/gtest.h"

namespace gl2d {

class RadiansTest : public ::testing::Test {
 protected:
  const double kPi = 3.14159265359;
  const double kPiDouble = 3.14159265359;
  const double k2PiDouble = 2 * kPiDouble;

  Radians kPiRadians;
  Radians k2PiRadians;

  Radians radian0_;
  Radians radian1_;
  Radians radian2_;
  Radians radian3_;
  Radians radian4_;
  Radians radian5_;
  Radians radian6_;
  Radians radian7_;
  Radians radian8_;

  virtual void SetUp() {
    radian0_.radians_ = kPi;
    radian1_.radians_ = 2 * kPi;
    radian2_.radians_ = kPi;
    radian3_.radians_ = kPi;
    radian4_.radians_ = 0.88965288066;
    radian5_.radians_ = 0;
    radian6_.radians_ = kPi / 2;
    radian7_.radians_ = kPi;
    radian8_.radians_ = (3 / 2.) * kPi;
  }

  virtual void ExpectEqual(const Radians& radians1, const Radians& radians2) {
    EXPECT_NEAR(radians1.radians_, radians2.radians_, 1e-10);
  }

  virtual void AssertAssignment(Radians* radians1, const Radians& radians2) {
    ASSERT_FALSE(radians1 == nullptr);
    radians1->radians_ = radians2.radians_;
    ASSERT_NEAR(radians1->radians_, radians2.radians_, 1e-10);
  }

 public:
  RadiansTest() {
    kPiRadians.radians_ = kPiDouble;
    k2PiRadians.radians_ = k2PiDouble;
  }
  ~RadiansTest() = default;
};

TEST_F(RadiansTest, Constructor) {
  Radians rad(kPi);

  ExpectEqual(rad, radian0_);
}

TEST_F(RadiansTest, Getters) {
  // TODO(monteiro)
}

TEST_F(RadiansTest, Setters) {
  // TODO(monteiro)
}

TEST_F(RadiansTest, Normalize) {
  // TODO(monteiro)
}

TEST_F(RadiansTest, Cosine) {
  EXPECT_NEAR(Radians::Cos(radian5_), 1, 1e-10);
  EXPECT_NEAR(Radians::Cos(radian6_), 0, 1e-10);
  EXPECT_NEAR(Radians::Cos(radian7_), -1, 1e-10);
  EXPECT_NEAR(Radians::Cos(radian8_), 0, 1e-10);
}

TEST_F(RadiansTest, Sine) {
  EXPECT_NEAR(Radians::Sin(radian5_), 0, 1e-10);
  EXPECT_NEAR(Radians::Sin(radian6_), 1, 1e-10);
  EXPECT_NEAR(Radians::Sin(radian7_), 0, 1e-10);
  EXPECT_NEAR(Radians::Sin(radian8_), -1, 1e-10);
}

TEST_F(RadiansTest, ArcCosine) {
  ExpectEqual(Radians::Acos(1), radian5_);
  ExpectEqual(Radians::Acos(0), radian6_);
  ExpectEqual(Radians::Acos(-1), radian0_);
}

TEST_F(RadiansTest, ArcSine) {
  ExpectEqual(Radians::Asin(1), radian6_);
  ExpectEqual(Radians::Asin(0), radian5_);
  ExpectEqual(Radians::Asin(-1), radian8_);
}

TEST_F(RadiansTest, Addition) {
  Radians r1;
  Radians r2;
  Radians r3;
  Radians r4;
  Radians r5;
  Radians r6;

  AssertAssignment(&r1, radian0_ + radian1_);
  AssertAssignment(&r4, radian0_);
  AssertAssignment(&r6, +radian2_);

  r4 += radian1_;

  ExpectEqual(r1, radian2_);
  ExpectEqual(r4, radian2_);
  ExpectEqual(r6, radian2_);
}

TEST_F(RadiansTest, Subtraction) {
  Radians r1;
  Radians r2;
  Radians r3;
  Radians r4;
  Radians r5;
  Radians r6;

  AssertAssignment(&r1, radian2_ - radian1_);
  AssertAssignment(&r4, radian2_);
  AssertAssignment(&r6, -radian3_);

  r4 -= radian1_;

  ExpectEqual(r1, radian0_);
  ExpectEqual(r4, radian0_);
  ExpectEqual(r6, radian0_);
}

TEST_F(RadiansTest, Product) {
  Radians r1;
  Radians r2;
  Radians r3;
  Radians r4;
  Radians r5;

  AssertAssignment(&r2, radian0_ * (2 * kPi));
  AssertAssignment(&r3, kPi * radian1_);
  AssertAssignment(&r5, radian0_);

  r5 *= 2 * kPi;

  ExpectEqual(r2, radian4_);
  ExpectEqual(r3, radian4_);
  ExpectEqual(r5, radian4_);
}

TEST_F(RadiansTest, Division) {
  Radians r1;
  Radians r2;
  Radians r3;
  Radians r4;
  Radians r5;

  AssertAssignment(&r2, radian1_ / 2);
  AssertAssignment(&r5, radian0_);

  r5 /= 2;

  ExpectEqual(r2, radian0_);
  ExpectEqual(r5, radian6_);
}

TEST_F(RadiansTest, DoubleAssignment) {
  Radians r1;
  r1 = kPi;

  ExpectEqual(r1, radian0_);
}

TEST_F(RadiansTest, EqualOperator) {
  // TODO(user)
}

TEST_F(RadiansTest, NotEqualOperator) {
  // TODO(user)
}

}  // namespace gl2d
