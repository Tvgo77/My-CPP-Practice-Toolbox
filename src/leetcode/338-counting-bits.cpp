#include "include/leetcode.h"

using std::vector;

class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }
        if (n == 1) {
            return {0, 1};
        }
        vector<int> dp(n + 1, -1);
        vector<int> minExponent(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        minExponent[0] = 1;
        minExponent[1] = 1;

        for (int i = 2; i <= n; i++) {
            /* Count bits */
            /* Find min k which 2^k >= n */
            int k = minExponent[i - 1];
            if (k * 2 <= i) 
                k *= 2;
            dp[i] = 1 + dp[i % k];
            minExponent[i] = k;
        }       
        return dp;
    }
};


// Test function
int main() {
    Solution solution;
    int input = 2;
    vector<int> expect = {0, 1, 1};
    testTool(&Solution::countBits, expect, input);

    return 0;
}