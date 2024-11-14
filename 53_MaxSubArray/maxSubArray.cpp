#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using std::unordered_set;
using std::string;
using std::vector;
using std::swap;
using std::max;
using std::min;
using std::cout;
using std::endl;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int curSum = 0;
        for (int num: nums) {
            if (curSum < 0) {
                curSum = 0;
            }
            curSum += num;
            ans = std::max(curSum, ans);
        }
        
        return ans;
    }
};