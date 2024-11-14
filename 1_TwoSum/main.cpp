#include <iostream>
#include "twoSum.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;

    vector<int> result = solution.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}