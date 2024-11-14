#include <iostream>
#include "maxSubArray.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4}; // expect 6
    // vector<int> nums = {1}; // expect 1
    vector<int> nums = {5,4,-1,7,8}; // expect 23
    cout << solution.maxSubArray(nums) << endl; 

    return 0;
}