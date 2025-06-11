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

#include <memory>

#include "components/container.hpp"

vui::Container::Container(void) {}

void vui::Container::addChild(std::shared_ptr<Component> child) {
  if (child) {
    children.push_back(child);
    child->setParent(std::dynamic_pointer_cast<Container>(shared_from_this()));
  }
}

void vui::Container::removeChild(const std::string &childId) {
  auto iterator =
      std::remove_if(children.begin(), children.end(),
                     [&childId](const std::shared_ptr<Component> &child) {
                       return child->getId() == childId;
                     });
  if (iterator != children.end()) {
    (*iterator)->setParent(std::shared_ptr<Container>());
    children.erase(iterator, children.end());
  }
}

void vui::Container::clearChildren(void) {
  for (const auto &child : children) {
    child->setParent(std::shared_ptr<Container>());
  }
  children.clear();
}

void vui::Container::render(Renderer &renderer) {
  for (const auto &child : children) {
    child->render(renderer);
  }
}

void vui::Container::update(void) {
  for (const auto &child : children) {
    child->update();
  }
}
