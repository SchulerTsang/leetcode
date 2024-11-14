#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using std::unordered_set;
using std::unordered_map;
using std::string;
using std::vector;
using std::swap;
using std::max;
using std::min;
using std::cout;
using std::endl;

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         // std::sort(nums.begin(), nums.end());

//         int len = nums.size();
//         vector<int> accumulativeSum(len + 1, 0); // 累加和

//         for (int i = 1; i <= len; i++) {
//             accumulativeSum[i] = accumulativeSum[i - 1] + nums[i - 1];
//         }

//         for (int i = 0; i <= len; i++) {
//             cout << "accumulative[" << i << "]: " << accumulativeSum[i] << endl;
//         }

//         // 用于遍历，acccumulativeSum[right] - accumulativeSum[left]表示
//         // 左闭右开区间nums[left, right)上的和
//         int ans = 0;
//         int left = 0, right = 1;
//         while (right <= len) {
//             int sum = accumulativeSum[right] - accumulativeSum[left];
//             if (sum < k) {
//                 ++right;
//             } else if (sum > k) {
//                 ++left;
//             } else {
//                 if (right > left) {
//                     ++ans;
//                 }
//                 ++right;
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int len = nums.size();
//         // 前缀和，有定义: prefixSum[i + 1] = nums[0] + nums[1] + num[2] + ... + nums[i]
//         // 又prefixSum[i] = nums[0] + nums[1] + num[2] + ... + nums[i - 1]
//         // 因此有: prefixSum[i + 1] = prefixSum[i] + nums[i];
//         vector<int> prefixSum(len + 1, 0); 

//         for (int i = 1; i <= len; i++) {
//             prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
//         }

//         int ans = 0;
//         unordered_map<int, int> freq;
//         // 枚举prefixSum[j]，遍历前缀和数组找到满足：prefixSum[i] - complement == k的complement的个数
//         for (int i = 0; i <= len; i++) {
//             // cout << "<------------------map start------------------->" << endl;
//             // for (auto pair : freq) {
//             //     cout << "key: " << pair.first << " value: " << pair.second << endl;
//             // }
//             // cout << "<------------------map end------------------->" << endl;

//             int complement = prefixSum[i] - k;

//             // cout << "k: " << k << ", prefixSum[" <<i << "]: " << prefixSum[i] << ", complement: " << complement << endl;
//             auto it = freq.find(complement);

//             if (it != freq.end()) {
//                 ans += it->second;
//             }

//             freq[prefixSum[i]] = freq.count(prefixSum[i]) == 0 ? 1 : freq[prefixSum[i]] + 1;
//         }         

//         return ans;
//     }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, pre = 0;
        unordered_map<int, int> cnt{{0, 1}}; // pre[0]=0 单独统计
        for (int x : nums) {
            pre += x;
            // 注意不要直接 += cnt[pre-k]，如果 pre-k 不存在，会插入 pre-k
            // ans += cnt.contains(pre - k) ? cnt[pre - k] : 0;
            ans += cnt.count(pre - k)  > 0 ? cnt[pre - k] : 0;
            cnt[pre]++;
        }

        return ans;
    }
};