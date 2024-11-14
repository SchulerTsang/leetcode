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

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 先对区间进行排序
       std::stable_sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            // First compare the first element
            if (a[0] != b[0]) {
                return a[0] < b[0];  // Ascending order of the first element
            }
            // If the first elements are equal, compare the second element
            return a[1] < b[1];  // Ascending order of the second element
        });

        vector<vector<int>> ans;
        int n = intervals.size();
        // intervals[0...left - 1]之间的区间为已经处理过的无重叠的区间
        // intervals[left...right]之间的区间为正在检查存在无重叠的区间
        // intervals[right...n - 1]之间的区间为待处理的区间

        // 一维区间是否重叠, a, b为已经排序后的区间；
        // 满足b[0] >= a[0] && b[1] > a[0], b[1] 与 a[1]的关系则未定
        auto intersect = [](const std::vector<int>& a, const std::vector<int>& b)->bool {
            // a, b代表的两区间不重叠
            if (b[0] > a[1]) {
                return false;
            }

            return true;
        };

        int left = 0, right = 1; // intervals[left]到intervals[right]之间的区间为不确定是否重叠的待处理区间
        while (right < n) {
            vector<int> tmp = intervals[left];
            while (right < n && intersect(tmp, intervals[right])) {
                tmp[1] = max(tmp[1], intervals[right][1]);
                ++right;
            }
            ans.push_back(tmp);
            left = right;
            ++right;
        }

        if (left < n) {
            ans.push_back({intervals[left][0], intervals[right - 1][1]});
        }

        return ans;
    }
};