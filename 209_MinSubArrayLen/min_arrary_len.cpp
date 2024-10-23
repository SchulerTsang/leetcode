#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(); 
        int ans = n + 1; // 初始化为n+1或无穷大，便于后续min操作
        int sum = 0; // 滑动窗口中的数值之和
        int left = 0; // 滑动窗口的左端点

        for (int right = 0; right < n; right++) { // 枚举子数组右端点
            sum += nums[right];
            while (sum - nums[left] >= target) { // 尽量缩小子数组长度
                sum -= nums[left]; 
                ++left; // 左端点右移
            }

            if (sum >= target) {
                // right - left + 1 即为滑动窗口的长度
                ans = min(ans, right - left + 1);
            }
        }

        return ans <= n ? ans : 0;
    }
};