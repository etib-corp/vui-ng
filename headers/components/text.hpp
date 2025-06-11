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

#include "component.hpp"
#include "renderer.hpp"

namespace vui {

class Text : public Component {
public:
  enum class TextAlign { Left, Center, Right, Justify };
  enum class FontWeight { Normal, Bold, Light };

private:
  std::string content;
  TextAlign textAlign = TextAlign::Left;
  FontWeight fontWeight = FontWeight::Normal;

public:
  Text(void);

  std::shared_ptr<Component> findById(const std::string &searchId) override {
    if (getId() == searchId) {
      return shared_from_this();
    }
    return nullptr;
  }

  const std::string &getContent() const { return content; }
  void setContent(const std::string &newContent) { content = newContent; }
  TextAlign getTextAlign() const { return textAlign; }
  void setTextAlign(TextAlign align) { textAlign = align; }
  FontWeight getFontWeight() const { return fontWeight; }
  void setFontWeight(FontWeight weight) { fontWeight = weight; }

  void render(Renderer &renderer) override;
  void update(void) override;
  std::string getType() const override { return "Text"; }
};

} // namespace vui