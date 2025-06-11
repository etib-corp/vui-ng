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

class Input : public Component {
public:
  enum class InputType { Text, Password, Email, Number };

private:
  std::string value;
  std::string placeholder;
  InputType inputType = InputType::Text;
  bool readonly = false;
  bool disabled = false;

public:
  Input(void);

  std::shared_ptr<Component> findById(const std::string &searchId) override {
    if (getId() == searchId) {
      return shared_from_this();
    }
    return nullptr;
  }

  const std::string &getValue() const { return value; }
  void setValue(const std::string &newValue);
  const std::string &getPlaceholder() const { return placeholder; }
  void setPlaceholder(const std::string &newPlaceholder) {
    placeholder = newPlaceholder;
  }
  InputType getInputType(void) const { return inputType; }
  void setInputType(InputType type) { inputType = type; }
  bool isReadonly(void) const { return readonly; }
  void setReadonly(bool newReadonly) { readonly = newReadonly; }
  bool isDisabled(void) const { return disabled; }
  void setDisabled(bool newDisabled) { disabled = newDisabled; }

  void render(Renderer &renderer) override;
  std::string getType() const override { return "Input"; }
  void update(void) override;

  void onChange(std::function<void()> handler) { bindEvent("change", handler); }
  void onFocus(std::function<void()> handler) { bindEvent("focus", handler); }
  void onBlur(std::function<void()> handler) { bindEvent("blur", handler); }
};

} // namespace vui