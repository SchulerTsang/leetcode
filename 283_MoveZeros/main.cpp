#include <iostream>
#include "moveZeros.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    vector<int> nums = {0,1,0,3,12};
    // vector<int> nums = {0};

    solution.moveZeroes(nums);
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}