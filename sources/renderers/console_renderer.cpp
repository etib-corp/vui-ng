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

#include "renderers/console_renderer.hpp"

vui::console_renderer::ConsoleRenderer::ConsoleRenderer(void)
    : _indentLevel(0), _opacity(1.0f), _visible(true) {
}

vui::console_renderer::ConsoleRenderer::ConsoleRenderer(int indentLevel,
                                            float opacity, bool visible)
    : _indentLevel(indentLevel), _opacity(opacity), _visible(visible) {
}

vui::console_renderer::ConsoleRenderer::~ConsoleRenderer(void) {
}

void vui::console_renderer::ConsoleRenderer::beginRender(void) {
    printIndent();
    std::cout << "Begin Render" << std::endl;
}

void vui::console_renderer::ConsoleRenderer::endRender(void) {
    printIndent();
    std::cout << "End Render" << std::endl;
}

void vui::console_renderer::ConsoleRenderer::pushTransform(float x, float y,
                                            float scaleX, float scaleY) {
    printIndent();
    std::cout << "Push Transform: (" << x << ", " << y << "), Scale: ("
              << scaleX << ", " << scaleY << ")" << std::endl;
}

void vui::console_renderer::ConsoleRenderer::popTransform(void) {
    printIndent();
    std::cout << "Pop Transform" << std::endl;
}

void vui::console_renderer::ConsoleRenderer::setClipRect(float x, float y,
                                            float width, float height) {
    printIndent();
    std::cout << "Set Clip Rect: (" << x << ", " << y << "), Size: ("
              << width << ", " << height << ")" << std::endl;
}

void vui::console_renderer::ConsoleRenderer::clearClipRect(void) {
    printIndent();
    std::cout << "Clear Clip Rect" << std::endl;
}

void vui::console_renderer::ConsoleRenderer::setOpacity(float opacity) {
    _opacity = opacity;
    printIndent();
    std::cout << "Set Opacity: " << _opacity << std::endl;
}

float vui::console_renderer::ConsoleRenderer::getOpacity(void) const {
    return _opacity;
}

void vui::console_renderer::ConsoleRenderer::setVisible(bool visible) {
    _visible = visible;
    printIndent();
    std::cout << "Set Visible: " << (_visible ? "true" : "false") << std::endl;
}

bool vui::console_renderer::ConsoleRenderer::isVisible(void) const {
    return _visible;
}

void vui::console_renderer::ConsoleRenderer::printIndent() {
    for (int i = 0; i < _indentLevel; i++) {
        std::cout << " ";
    }
}