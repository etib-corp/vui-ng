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

#include <vector>

#include "componentable.hpp"

namespace vui {

class Component : public Componentable {
private:
  bool _visible = true;
  std::vector<std::shared_ptr<Component>> _children;

public:
  virtual ~Component(void);
  virtual void render(std::shared_ptr<Renderer> renderer) = 0;
  virtual void update(float deltaTime) = 0;

  bool is_visible(void) const { return _visible; }

  void set_visible(bool visible) { _visible = visible; }

  void add_child(std::shared_ptr<Component> child) {
    if (child) {
      _children.push_back(child);
    }
  }

  const std::vector<std::shared_ptr<Component>> &get_children(void) const {
    return _children;
  }
};

} // namespace vui
