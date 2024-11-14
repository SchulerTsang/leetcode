#include <iostream>
#include "longestConsecutive.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    // vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    cout << solution.longestConsecutive(nums) << endl;

    return 0;
}