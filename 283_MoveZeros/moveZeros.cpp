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

// class Solution {
// public:
//     // 使用额外空间解决
//     void moveZeroes(vector<int>& nums) {
//         vector<int> copy = nums;
//         int left = 0, right = copy.size() - 1;
//         int i = 0;
//         while (left <= right) {
//             if (copy[i] == 0) { // 0，复制到最后
//                 nums[right] = copy[i];
//                 right--;
//             } else { // 非零，复制到前面
//                 nums[left] = copy[i];
//                 left++;
//             }
//             ++i;
//             // cout << "input nums: " << endl;
//             // for (size_t i = 0; i < nums.size(); i++) {
//             //     cout << nums[i] << " ";
//             // }
//             // cout << endl;
//             // cout << "left: " << left << ", right: " << right << endl;
//         }
//     }
// };

class Solution {
public:
    /**
     * @brief Move all the zeros to the end of the array.
     * @note No extra space is used.
     * @param[in,out] nums The input array.
     */
    void moveZeroes(vector<int>& nums) {
        size_t len = nums.size();
        size_t i = 0, nonZero = 0;
        while (i < len) {
            if (nums[i] != 0) {
                swap(nums[i], nums[nonZero]);
                nonZero++;
            }
            i++;
        }
    }
};