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

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "component.hpp"
#include "renderer.hpp"
#include "state_manager.hpp"

namespace vui {

class Interface {
private:
  std::shared_ptr<Component> rootComponent;
  std::unique_ptr<Renderer> renderer;
  std::unique_ptr<StateManager> stateManager;

  mutable std::unordered_map<std::string, std::shared_ptr<Component>>
      componentCache;

  void clearComponentCache(void);
  void rebuildInterface(void);

public:
  Interface(std::unique_ptr<Renderer> renderer)
      : renderer(std::move(renderer)) {}
  ~Interface(void) = default;

  void render(void);
  void update(void);

  std::shared_ptr<Component> findComponent(const std::string &id) const;
  void bindEvent(const std::string &componentId, const std::string &eventType,
                 std::function<void()> handler);

  void setState(const std::string &key, const std::string &value);
  std::string getState(const std::string &key,
                       const std::string &defaultValue = "") const;

  void observeState(
      const std::string &key,
      std::function<void(const std::string &, const std::string &)> handler);

  void setRenderer(std::unique_ptr<Renderer> newRenderer);
  Renderer *getRenderer() const { return renderer.get(); }

  void initialize();
  void cleanup();
};

} // namespace vui