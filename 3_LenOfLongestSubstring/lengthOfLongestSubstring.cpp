#include <unordered_set>
#include <iostream>
#include <algorithm>

using std::unordered_set;
using std::string;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0, left = 0;
        unordered_set<char> window; // 维护从下标 left 到下标 right 的字符
        for (int right = 0; right < n; right++) {
            char c = s[right];
            // 如果窗口内已经包含 c，那么再加入一个 c 会导致窗口内有重复元素
            // 所以要在加入 c 之前，先移出窗口内的 c
            while (window.count(c)) { // 窗口内有 c
                window.erase(s[left++]); // 缩小窗口
            }
            window.insert(c); // 加入 c
            ans = max(ans, right - left + 1); // 更新窗口长度最大值
        }
        
        return ans;
    }
};