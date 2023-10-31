#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <stdint.h>

using namespace std;

int main() {
  int64_t n, h0, a, c, q;
  scanf("%ld %ld %ld %ld %ld", &n, &h0, &a, &c, &q);
  // 5 5 1 -1 1000
  int64_t output = 0;

  if (n == 1) {
    printf("%ld\n", int64_t(0));
    return 0;
  }
  
  /* Calculate heights of every person */
  std::vector<int64_t> heights(n, 0);
  heights[0] = h0;
  for (int64_t i = 1; i < n; i++) {
    heights[i] = (a * heights[i - 1] + c) % q;
  }

  /* Use Stack */
  std::stack<int64_t> heightStack;
  for (int64_t i = 0; i < n; i++) {
    if (heightStack.empty()) {
      heightStack.push(heights[i]);
    }
    else {
      if (heights[i] < heightStack.top()) {
        heightStack.push(heights[i]);
      }
      else {
        while (!heightStack.empty() && heights[i] >= heightStack.top()) {
          output += heightStack.size() - 1;
          heightStack.pop();
          output++;
        }
        heightStack.push(heights[i]);
      }
    }
  }
  output += heightStack.size() * (heightStack.size() - 1) / 2;

  printf("%ld\n", output);

  return 0;
}