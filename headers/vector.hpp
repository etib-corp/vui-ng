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
#pragma once

#include <array>
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace vui {

template <typename Type, std::size_t Size> class Vector {
private:
  std::array<Type, Size> _data{};

public:
  Vector() = default;

  Vector(std::initializer_list<Type> values) {
    std::size_t i = 0;
    for (auto val : values) {
      if (i >= Size)
        break;
      _data[i++] = val;
    }
  }

  Type &operator[](std::size_t index) {
    if (index >= Size)
      throw std::out_of_range("Vector index out of range");
    return _data[index];
  }

  const Type &operator[](std::size_t index) const {
    if (index >= Size)
      throw std::out_of_range("Vector index out of range");
    return _data[index];
  }

  Vector operator+(const Vector &other) const {
    Vector result;
    for (std::size_t i = 0; i < Size; ++i)
      result[i] = _data[i] + other[i];
    return result;
  }

  Vector operator-(const Vector &other) const {
    Vector result;
    for (std::size_t i = 0; i < Size; ++i)
      result[i] = _data[i] - other[i];
    return result;
  }

  Vector operator*(Type scalar) const {
    Vector result;
    for (std::size_t i = 0; i < Size; ++i)
      result[i] = _data[i] * scalar;
    return result;
  }

  Vector operator/(Type scalar) const {
    Vector result;
    for (std::size_t i = 0; i < Size; ++i)
      result[i] = _data[i] / scalar;
    return result;
  }

  Vector &operator+=(const Vector &other) {
    for (std::size_t i = 0; i < Size; ++i)
      _data[i] += other[i];
    return *this;
  }

  Vector &operator-=(const Vector &other) {
    for (std::size_t i = 0; i < Size; ++i)
      _data[i] -= other[i];
    return *this;
  }

  Vector &operator*=(Type scalar) {
    for (std::size_t i = 0; i < Size; ++i)
      _data[i] *= scalar;
    return *this;
  }

  Vector &operator/=(Type scalar) {
    for (std::size_t i = 0; i < Size; ++i)
      _data[i] /= scalar;
    return *this;
  }

  Type dot(const Vector &other) const {
    Type sum = 0;
    for (std::size_t i = 0; i < Size; ++i)
      sum += _data[i] * other[i];
    return sum;
  }

  Type magnitude() const { return std::sqrt(dot(*this)); }

  Vector normalized() const {
    Type mag = magnitude();
    if (mag == 0)
      return *this;
    return *this / mag;
  }

  bool operator==(const Vector &other) const {
    for (std::size_t i = 0; i < Size; ++i)
      if (_data[i] != other[i])
        return false;
    return true;
  }

  bool operator!=(const Vector &other) const { return !(*this == other); }

  const std::array<Type, Size> &data() const { return _data; }
};

template <typename Type, std::size_t Size>
std::ostream &operator<<(std::ostream &os, const Vector<Type, Size> &vec);

} // namespace vui
