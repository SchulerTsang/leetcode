#include <iostream>
#include "subarray_sum.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int k = 3;

    // vector<int> nums = {1, 1, 1};
    // int k = 2;

    // vector<int> nums = {1};
    // int k = 0;

    // vector<int> nums = {-1,-1, 1};
    // int k = 0;

    cout << solution.subarraySum(nums, k) << endl;  

    return 0;
}