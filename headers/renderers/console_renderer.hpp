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

#include "renderer.hpp"

#include <iostream>

namespace vui {

namespace console_renderer {

class ConsoleRenderer : public Renderer {

public:
    ConsoleRenderer(void);
    ConsoleRenderer(int indentLevel, float opacity = 1.0f,
                    bool visible = true);
    ~ConsoleRenderer(void);

    void beginRender(void) override;
    void endRender(void) override;

    void pushTransform(float x, float y, float scaleX = 1.0f,
                        float scaleY = 1.0f) override;
    void popTransform(void) override;
    void setClipRect(float x, float y, float width, float height) override;
    void clearClipRect(void) override;

    void setOpacity(float opacity) override;
    float getOpacity(void) const override;
    void setVisible(bool visible) override;
    bool isVisible(void) const override;

private:
    /**
     * Prints the current indentation level to the console.
     * This is used to visually represent the nesting of rendering commands.
     * It prints spaces based on the current indent level.
     * Indent level of 1 corresponds to 1 spaces, level 2 to 2 spaces, etc.
     */
    void printIndent();

    int _indentLevel;
    float _opacity;
    bool _visible;

};

} // namespace console_renderer

} // namespace vui