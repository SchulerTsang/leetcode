#include <iostream>
#include "rotate.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    // vector<int> nums = {1,2,3,4,5,6,7};
    // int k = 3;

    // vector<int> nums = {-1,-100,3,99};
    // int k = 2;

    vector<int> nums = {1};
    int k = 0;

    solution.rotate(nums, k);
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}