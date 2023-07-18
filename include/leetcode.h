#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <cstdint>

class Solution;

template <typename Func, typename Expect, typename... Args>
auto testTool(Func&& func, Expect&& expect, Args&&... args) {
    Solution solution;
    auto testFunc = std::bind(std::forward<Func>(func), &solution, std::forward<Args>(args)...);
    auto output = testFunc();
    bool b = (expect == output);
    return b;
}