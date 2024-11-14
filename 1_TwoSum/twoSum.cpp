#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>>

using std::unordered_map;
using std::string;
using std::map;
using std::vector;
using std::sort;

// class Solution {
// public:
    // // 哈希表解决twoSum问题
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     // map<int, int> map;
    //     unordered_map<int, int> map;
    //     vector<int> result;
    //     int len = nums.size();
    //     for (int i = 0; i < len; i++) {
    //         if (map.find(target - nums[i]) != map.end()) {
    //             result.push_back(map[target - nums[i]]);
    //             result.push_back(i);
    //             break;
    //         }
    //         map[nums[i]] = i;
    //     }
                 
    //     return result;
    // }
// };

class Solution {
public:
    // 排序+双指针解决twoSum问题
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // 排序
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        vector<int> result;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                result.push_back(left);
                result.push_back(right);
                break;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else if (nums[left] + nums[right] > target) {
                right--;
            }
        }
        return result;
    }
};