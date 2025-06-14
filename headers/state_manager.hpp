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
#include <string>
#include <unordered_map>
#include <vector>

namespace vui {

class StateManager {
private:
  std::unordered_map<std::string, std::string> globalState;

private:
  std::unordered_map<std::string,
                     std::vector<std::function<void(const std::string &,
                                                    const std::string &)>>>
      observers;

  void notifyObservers(const std::string &key, const std::string &value);

public:
  StateManager(void) = default;
  ~StateManager(void) = default;

  void setState(const std::string &key, const std::string &value) {
    globalState[key] = value;
  }

  std::string getState(const std::string &key,
                       const std::string &defaultValue = "") const {
    auto iterator = globalState.find(key);
    return (iterator != globalState.end()) ? iterator->second : defaultValue;
  }

  void addStateObserver(
      const std::string &key,
      std::function<void(const std::string &, const std::string &)> handler) {
    observers[key].push_back(handler);
  }

  void removeStateObserver(const std::string &key) { observers.erase(key); }
};

} // namespace vui
