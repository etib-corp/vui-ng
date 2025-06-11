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
#include <string>
#include <unordered_map>
#include <functional>

// Forward declarations
namespace vui {
class Container;
class Renderer;
}

namespace vui {

class Component : public std::enable_shared_from_this<Component> {
public:
private:
  std::string id;
  std::string className;
  std::unordered_map<std::string, std::string> props;
  std::unordered_map<std::string, std::string> style;
  std::unordered_map<std::string, std::function<void()>> eventHandlers;
  std::unordered_map<std::string, std::string> state;
  std::shared_ptr<Container> parent;

public:
  Component() = default;
  virtual ~Component() = default;

  // Identification methods
  const std::string &getId() const { return id; }
  void setId(const std::string &newId) { id = newId; }
  const std::string &getClassName() const { return className; }
  void setClassName(const std::string &newClassName) {
    className = newClassName;
  }
  virtual std::string getType() const = 0;

  // Properties and styles methods
  void setProperty(const std::string &key, const std::string &value) {
    props[key] = value;
  }

  std::string getProperty(const std::string &key,
                          const std::string &defaultValue = "") const {
    auto iterator = props.find(key);
    return (iterator != props.end()) ? iterator->second : defaultValue;
  }

  void setStyle(const std::string &key, const std::string &value) {
    style[key] = value;
  }

  std::string getStyle(const std::string &key,
                       const std::string &defaultValue = "") const {
    auto iterator = style.find(key);
    return (iterator != style.end()) ? iterator->second : defaultValue;
  }

  virtual void render(Renderer &renderer) = 0;
  virtual void update();

  void bindEvent(const std::string &eventType, std::function<void()> handler) {
    eventHandlers[eventType] = handler;
  }

  void handleEvent(const std::string &eventType) {
    auto iterator = eventHandlers.find(eventType);
    if (iterator != eventHandlers.end()) {
      iterator->second();
    }
  }

  virtual std::shared_ptr<Component> findById(const std::string &searchId) = 0;

  void setState(const std::string &key, const std::string &value) {
    state[key] = value;
    onStateChange(key, value);
  }

  std::string getState(const std::string &key,
                       const std::string &defaultValue = "") const {
    auto iterator = state.find(key);
    return (iterator != state.end()) ? iterator->second : defaultValue;
  }

  // Tree navigation
  void setParent(std::shared_ptr<Container> newParent) { parent = newParent; }
  std::shared_ptr<Container> getParent() const { return parent; }

protected:
  virtual void onStateChange(const std::string &key, const std::string &value) {
  }

  const std::unordered_map<std::string, std::string> &getProps() const {
    return props;
  }
  const std::unordered_map<std::string, std::string> &getStyles() const {
    return style;
  }
};

} // namespace vui
