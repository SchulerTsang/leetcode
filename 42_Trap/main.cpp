#include <iostream>
#include "trap.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> height = {4,2,0,3,2,5};

    cout << solution.trap(height) << endl;  

    return 0;
}