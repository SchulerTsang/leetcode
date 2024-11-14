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

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int len = height.size();
//         vector<int> left_max(len, 0); 
//         vector<int> right_max(len, 0);
//         vector<int> minLR(len, 0); // left_max[i]和right_max[i]的最小值
        
//         // 获取前缀最大值，left_max[0]因为是最左端，所以为0
//         for (int i = 1; i < len; i++) {
//             left_max[i] = max(left_max[i - 1], height[i - 1]);
//         }

//         // 获取后缀最大值，right_max[len - 1]因为是最右端，所以为0
//         for (int i = len - 2; i >= 0; i--) {
//             right_max[i] = max(right_max[i + 1], height[i + 1]);
//         }

//         // 获取最小值
//         for (int i = 0; i < len; i++) {
//             minLR[i] = min(left_max[i], right_max[i]);
//         }

//         for (int i = 0; i < len; i++) {
//             cout << minLR[i] << " ";
//         }
//         cout << endl;
        
        
//         // 累加
//         int ans = 0;
//         for (int i = 0; i < len; i++) {
//             ans += minLR[i] >= height[i] ? minLR[i] - height[i] : 0;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    // 前缀和（改进版），无需对正负号进行处理
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> left_max(len, 0); // left_max[i]是height[0]到height[i]的最大值
        vector<int> right_max(len, 0); // right_max[i]是height[i]到height[len-1]的最大值
        
        // 获取前缀最大值
        left_max[0] = height[0];
        for (int i = 1; i < len; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // 获取后缀最大值
        right_max[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        
        // 累加
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }

        return ans;
    }
};