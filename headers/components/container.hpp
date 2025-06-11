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

#include <memory>
#include <vector>

#include "component.hpp"
#include "renderer.hpp"

namespace vui {

class Container : public Component {
private:
  std::vector<std::shared_ptr<Component>> children;

public:
  enum class LayoutType { None, Flex, Grid, Absolute };

  virtual ~Container() noexcept override = default;

private:
  LayoutType layoutType = LayoutType::None;

public:
  Container(void);

  std::shared_ptr<Component> findById(const std::string &searchId) override {
    if (getId() == searchId) {
      return shared_from_this();
    }
    for (const auto &child : children) {
      auto found = child->findById(searchId);
      if (found) {
        return found;
      }
    }
    return nullptr;
  }

  void addChild(std::shared_ptr<Component> child);
  void removeChild(const std::string &childId);
  void clearChildren(void);
  const std::vector<std::shared_ptr<Component>> &getChildren() const {
    return children;
  }

  LayoutType getLayoutType() const { return layoutType; }
  void setLayoutType(LayoutType type) { layoutType = type; }

  void render(Renderer &renderer) override;
  void update(void) override;
  std::string getType(void) const override { return "Container"; }
};

} // namespace vui
