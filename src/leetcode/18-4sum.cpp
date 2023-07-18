#include "include/leetcode.h"

using std::vector;
using std::set;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> checkedPair;

        std::sort(nums.begin(), nums.end());

        if (nums.size() < 4) {
            return {};
        }


        set<vector<int>> output;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                /* Check if (nums[i], nums[j]) has been calculated */
                vector<int> numPair = {nums[i], nums[j]};
                std::sort(numPair.begin(), numPair.end());
                if (checkedPair.count(numPair) > 0) {
                    continue;
                }


                /* Target for 2sum */
                std::int64_t target2sum = std::int64_t(target) - std::int64_t(nums[i]) - std::int64_t(nums[j]);
                /* 2Sum start */ 
                int frontIdx = 0;
                int backIdx = nums.size() - 1;

                if (frontIdx == i || frontIdx == j) {
                    frontIdx++;
                    if (frontIdx == j) {
                        frontIdx++;
                    }
                }
                if (backIdx == j || backIdx == i) {
                    backIdx--;
                    if (backIdx == i) {
                        backIdx--;
                    }
                }

                while (true) {
                    // printf("%d, %d, %d, %d\n", i, j, frontIdx, backIdx);
                    if (std::int64_t(nums[frontIdx]) + std::int64_t(nums[backIdx]) == target2sum) {
                        vector<int> quadruplets = {nums[i], nums[j], nums[frontIdx], nums[backIdx]};
                        std::sort(quadruplets.begin(), quadruplets.end());
                        output.insert(quadruplets);

                        vector<int> numPair = {nums[i], nums[j]};
                        std::sort(numPair.begin(), numPair.end());
                        checkedPair.insert(numPair);

                        frontIdx++;
                    }

                    else if (std::int64_t(nums[frontIdx]) + std::int64_t(nums[backIdx]) < target2sum) {
                        frontIdx++;
                    }

                    else if (std::int64_t(nums[frontIdx]) + std::int64_t(nums[backIdx]) > target2sum) {
                        backIdx--;
                    }

                    if (frontIdx == i || frontIdx == j) {
                        frontIdx++;
                        if (frontIdx == j) {
                            frontIdx++;
                        }
                    }
                    if (backIdx == j || backIdx == i) {
                        backIdx--;
                        if (backIdx == i) {
                            backIdx--;
                        }
                    }

                    if (frontIdx == backIdx) {
                        break;
                    }
                }
            }
        }
        vector<vector<int>> result(output.begin(), output.end());
        return result;
    }
};

// Test function
int main() {
    Solution solution;
    vector<vector<int>> expect = {{2, 2, 2, 2}};
    vector<int> input1 = {2,2,2,2,2};
    int input2 = 8;
    testTool(&Solution::fourSum, expect, input1, input2);

    return 0;
}