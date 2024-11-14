#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using std::unordered_set;
using std::string;
using std::vector;
using std::swap;
using std::cout;
using std::endl;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ranges::sort(nums);
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int x = nums[i];
            // i > 0 && x == nums[i - 1]
            if (i && x == nums[i - 1]) continue; // 跳过重复数字
            // 最小的三元组之和也大于0，直接退出
            if (x + nums[i + 1] + nums[i + 2] > 0) break; // 优化一
            // 对于本轮的x，最大的三元组之和小于0，结束该轮
            if (x + nums[n - 2] + nums[n - 1] < 0) continue; // 优化二
            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = x + nums[j] + nums[k];
                if (s > 0) {
                    k--;
                } else if (s < 0) {
                    j++;
                } else {
                    ans.push_back({x, nums[j], nums[k]});
                    for (j++; j < k && nums[j] == nums[j - 1]; j++); // 跳过重复数字
                    for (k--; k > j && nums[k] == nums[k + 1]; k--); // 跳过重复数字
                }
            }
        }
        return ans;
    }
};