#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using std::unordered_map;
using std::string;
using std::vector;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        for (auto &s : strs) {
            string sorted_s = s;
            std::sort(sorted_s.begin(), sorted_s.end());
            m[sorted_s].push_back(s); // sorted_s 相同的字符串分到同一组
        }

        vector<vector<string>> ans;
        ans.reserve(m.size()); // 预分配空间
        // for (auto &[_, value] : m) {
        //     ans.push_back(value);
        // }
        ans.reserve(m.size()); 
        for (const auto& pair : m) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};