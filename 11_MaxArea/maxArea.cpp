#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;

// class Solution {
// public:
//     // 暴力法解决
//     int maxArea(vector<int>& height) {
//         size_t len = height.size();
//         int max = 0;
//         // size_t left = 0, right = height.size() - 1;
//         for (size_t i = 0; i < len; i++)
//         {
//             int area = 0;
//             for (size_t j = i + 1; j < len; j++) {
//                 area = std::min(height[i], height[j]) * (j - i);
//                 max = std::max(max ,area);
//             }
//         }

//         return max;
//     }
// };

class Solution {
public:
    // 双指针法解决
    int maxArea(vector<int>& height) {
        size_t left = 0, right = height.size() - 1;
        int max = 0;
        while (left < right) {
            int area = std::min(height[left], height[right]) * (right - left);
            max = std::max(area, max);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
};