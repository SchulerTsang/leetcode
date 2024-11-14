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
//     void rotate(vector<int>& nums, int k) {
//         // 确定循环起始位置
//         int n = nums.size();
//         k = (n - (k % n)) % n;
//         vector<int> rotatedVec;
//         rotatedVec.reserve(n);

//         for (int i = 0; i < n; i++) {
//             // cout << "k: " << k << endl;
//             rotatedVec.push_back(nums[k]);
//             k = (k + 1) % n;
//         }
        
//         for (int i = 0; i < n; i++) {
//             nums[i] = rotatedVec[i];
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto reverse = [&](int i, int j) {
            while (i < j) {
                swap(nums[i++], nums[j--]);
            }
        };

        int n = nums.size();
        k %= n; // 轮转 k 次等于轮转 k%n 次
        reverse(0, n - 1);
        reverse(0, k - 1); // 将前 k 个元素翻转
        reverse(k, n - 1); // 将后 n - k 个元素翻转
    }
};