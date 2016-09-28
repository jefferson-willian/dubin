#ifndef GL2D_INCLUDE_VECTOR_H_
#define GL2D_INCLUDE_VECTOR_H_

#include "gl2d/point.h"
#include "gl2d/radians.h"

#ifdef _UNIT_TESTING_
#include "gtest/gtest.h"
#endif

namespace gl2d {

class Vector {
 protected:
  // Vector's destination point. The vector's origin is always (0,0).
  ::gl2d::Point dest_;

 public:
  // Creates a vector with destination point (x,y).
  explicit Vector(double x, double y);
  // Creates a vector with destination point |dest|.
  explicit Vector(const ::gl2d::Point& dest);
  // Creates a vector that has origin in |orig| and destination in |dest|, then
  // the vector is translated to the origin (0,0).
  explicit Vector(const ::gl2d::Point& orig, const ::gl2d::Point& dest);
  Vector() = default;
  ~Vector() = default;

  // Get x-coordinate.
  double x() const;

  // Set x-coordinate.
  void x(double x);

  // Get y-coordinate.
  double y() const;

  // Set y-coordinate.
  void y(double y);

  // Get the vector destination point.
  const ::gl2d::Point& Point() const;

  // Get the vector magnitude.
  double Magnitude() const;

  // Set vector magnitude.
  void Magnitude(double magnitude);

  // Normalize vector.
  Vector& Normalize();

  // Returns the vector's angle.
  Radians Angle() const;

  // Rotate the vector |angle| radians.
  Vector& Rotate(const Radians& angle);

  // Mathematical operators.
  Vector& operator+=(const Vector& v);
  Vector& operator-=(const Vector& v);
  Vector& operator*=(double k);
  Vector& operator/=(double k);

  friend Vector operator+(const Vector& v);
  friend Vector operator+(const Vector& v, const Vector& w);
  friend Vector operator-(const Vector& v, const Vector& w);
  friend Vector operator-(const Vector& v);
  friend Vector operator*(const Vector& v, double k);
  friend Vector operator*(double k, const Vector& v);
  friend Vector operator/(const Vector& v, double k);

  bool operator==(const Vector& v) const;
  bool operator!=(const Vector& v) const;

  // Canonical vectors.
  static const Vector i;
  static const Vector j;

#ifdef _UNIT_TESTING_
  // Friend test classes.
  friend class VectorTest;
  FRIEND_TEST(VectorTest, Constructor);
  FRIEND_TEST(VectorTest, Setters);
  FRIEND_TEST(VectorTest, Normalize);
  FRIEND_TEST(VectorTest, Rotation);
  FRIEND_TEST(VectorTest, Addition);
  FRIEND_TEST(VectorTest, Subtraction);
  FRIEND_TEST(VectorTest, ScalarProduct);
  FRIEND_TEST(VectorTest, ScalarDivision);
  FRIEND_TEST(VectorTest, Canonical);
#endif
};

}  // namespace gl2d

#endif  // GL2D_INCLUDE_VECTOR_H_
