#include "include/leetcode.h"

using std::vector;
using std::set;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> output;
        set<int> checked_num;

        /* Sort nums  */
        auto frontIter = nums.begin();
        auto backIter = nums.end();
        std::sort(frontIter, backIter);;

        /* Loop for every number in nums */
        for (int i = 0; i < nums.size(); i++) {
            if (checked_num.count(nums[i]) > 0)
                continue;
            /* init 2 pointer at front and end */
            int frontIdx = (i == 0)? 1: 0;
            int backIdx = (i == nums.size() - 1)? nums.size() - 2: nums.size() - 1;

            /* Add 3 nums if result > 0, < 0, == 0 */
            while (true) {
                int result = nums[i] + nums[frontIdx] + nums[backIdx];
                if (result > 0) {
                    backIdx--;
                    if (backIdx == i)
                        backIdx--;
                }
                else if (result < 0) {
                    frontIdx++;
                    if (frontIdx == i)
                        frontIdx++;
                }
                else if (result == 0) {
                    vector<int> triplet = {nums[i], nums[frontIdx], nums[backIdx]};
                    std::sort(triplet.begin(), triplet.end());
                    output.insert(triplet);
                    frontIdx++;
                    if (frontIdx == i)
                        frontIdx++;
                }

                if (frontIdx == backIdx) {
                    checked_num.insert(nums[i]);
                    break;
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
    vector<vector<int>> expect = {{-1, 0, 1}};
    vector<int> input = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    testTool(&Solution::threeSum, expect, input);

    return 0;
}