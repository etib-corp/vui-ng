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

#include <string>
#include <functional>

#include "component.hpp"
#include "renderer.hpp"

namespace vui {

class Button : public Component {
private:
  std::string text;
  bool enabled = true;

protected:
  void onStateChange(const std::string &key, const std::string &value) override;

public:
  Button(void);

  std::shared_ptr<Component> findById(const std::string &searchId) override {
    if (getId() == searchId) {
      return shared_from_this();
    }
    return nullptr;
  }

  const std::string &getText() const { return text; }
  void setText(const std::string &newText) { text = newText; }
  bool isEnabled() const { return enabled; }
  void setEnabled(bool newEnabled) { enabled = newEnabled; }

  void render(Renderer &renderer) override;
  void update(void) override;

  std::string getType() const override { return "Button"; }

  void onClick(std::function<void()> handler) { bindEvent("click", handler); }
};

} // namespace vui