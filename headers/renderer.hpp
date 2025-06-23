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

namespace vui {

class Renderer {

public:
  virtual ~Renderer(void) = default;

  virtual void beginRender(void) = 0;
  virtual void endRender(void) = 0;

  virtual void pushTransform(float x, float y, float scaleX = 1.0f,
                             float scaleY = 1.0f) = 0;
  virtual void popTransform(void) = 0;
  virtual void setClipRect(float x, float y, float width, float height) = 0;
  virtual void clearClipRect(void) = 0;

  virtual void setOpacity(float opacity) = 0;
  virtual float getOpacity(void) const = 0;
  virtual void setVisible(bool visible) = 0;
  virtual bool isVisible(void) const = 0;
};


} // namespace vui
