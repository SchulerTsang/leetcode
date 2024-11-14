#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using std::unordered_set;
using std::string;
using std::vector;

class Solution {
public:
    /**
     * Finds the longest consecutive sequence of numbers in a given set.
     *
     * @param nums a vector of integers
     * @return the length of the longest consecutive sequence
     */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (const auto &num : nums) {
            if (numSet.find(num - 1) == numSet.end()) { // If the number is the start of a sequence
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    ++length;
                }
                longest = std::max(longest, length);
            }
        }

        return longest;
    }
};