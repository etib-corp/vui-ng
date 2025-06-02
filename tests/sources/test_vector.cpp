/*
 Copyright (c) 2025 ETIB

 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do
 so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <gtest/gtest.h>

#include "vector.hpp"

#include "test_vector.hpp"

TEST(VectorTest, DefaultConstructor) {
  vui::Vector<int, 3> v;
  EXPECT_EQ(v[0], 0);
  EXPECT_EQ(v[1], 0);
  EXPECT_EQ(v[2], 0);
}

TEST(VectorTest, InitializerList) {
  vui::Vector<float, 3> v{1.0f, 2.0f, 3.0f};
  EXPECT_FLOAT_EQ(v[0], 1.0f);
  EXPECT_FLOAT_EQ(v[1], 2.0f);
  EXPECT_FLOAT_EQ(v[2], 3.0f);
}

TEST(VectorTest, OutOfRangeThrows) {
  vui::Vector<int, 2> v{1, 2};
  EXPECT_THROW(v[2], std::out_of_range);
  EXPECT_THROW((const_cast<const vui::Vector<int, 2> &>(v)[2]),
               std::out_of_range);
}

TEST(VectorTest, Addition) {
  vui::Vector<int, 2> a{1, 2}, b{3, 4};
  vui::Vector<int, 2> c = a + b;
  EXPECT_EQ(c[0], 4);
  EXPECT_EQ(c[1], 6);
}

TEST(VectorTest, Subtraction) {
  vui::Vector<int, 2> a{5, 7}, b{2, 3};
  vui::Vector<int, 2> c = a - b;
  EXPECT_EQ(c[0], 3);
  EXPECT_EQ(c[1], 4);
}

TEST(VectorTest, ScalarMultiplication) {
  vui::Vector<double, 2> v{2.0, 3.0};
  auto r = v * 2.0;
  EXPECT_DOUBLE_EQ(r[0], 4.0);
  EXPECT_DOUBLE_EQ(r[1], 6.0);
}

TEST(VectorTest, ScalarDivision) {
  vui::Vector<double, 2> v{4.0, 6.0};
  auto r = v / 2.0;
  EXPECT_DOUBLE_EQ(r[0], 2.0);
  EXPECT_DOUBLE_EQ(r[1], 3.0);
}

TEST(VectorTest, CompoundAssignment) {
  vui::Vector<int, 2> v{1, 2}, w{3, 4};
  v += w;
  EXPECT_EQ(v[0], 4);
  EXPECT_EQ(v[1], 6);
  v -= w;
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  v *= 2;
  EXPECT_EQ(v[0], 2);
  EXPECT_EQ(v[1], 4);
  v /= 2;
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
}

TEST(VectorTest, DotProduct) {
  vui::Vector<int, 3> v{1, 2, 3};
  vui::Vector<int, 3> w{4, 5, 6};
  EXPECT_EQ(v.dot(w), 1 * 4 + 2 * 5 + 3 * 6);
}

TEST(VectorTest, Magnitude) {
  vui::Vector<double, 2> v{3.0, 4.0};
  EXPECT_DOUBLE_EQ(v.magnitude(), 5.0);
}

TEST(VectorTest, Normalized) {
  vui::Vector<double, 2> v{3.0, 4.0};
  auto n = v.normalized();
  EXPECT_NEAR(n[0], 0.6, 1e-6);
  EXPECT_NEAR(n[1], 0.8, 1e-6);
}

TEST(VectorTest, EqualityOperators) {
  vui::Vector<int, 3> a{1, 2, 3}, b{1, 2, 3}, c{3, 2, 1};
  EXPECT_TRUE(a == b);
  EXPECT_FALSE(a != b);
  EXPECT_FALSE(a == c);
  EXPECT_TRUE(a != c);
}

TEST(VectorTest, DataAccessor) {
  vui::Vector<int, 2> v{7, 8};
  auto arr = v.data();
  EXPECT_EQ(arr[0], 7);
  EXPECT_EQ(arr[1], 8);
}

TEST(VectorTest, ZeroMagnitudeNormalized) {
  vui::Vector<double, 2> v{0.0, 0.0};
  auto n = v.normalized();
  EXPECT_DOUBLE_EQ(n[0], 0.0);
  EXPECT_DOUBLE_EQ(n[1], 0.0);
}

TEST(VectorTest, ChainedOperations) {
  vui::Vector<int, 2> v{1, 2}, w{3, 4};
  auto r = (v + w) * 2 - w;
  EXPECT_EQ(r[0], 5);
  EXPECT_EQ(r[1], 8);
}
