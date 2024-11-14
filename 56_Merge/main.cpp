#include <iostream>
#include "merge.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;

    // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
    vector<vector<int>> ans = solution.merge(intervals);
    for (auto i : ans) {
        cout << i[0] << " " << i[1] << endl;
    }   
    
    return 0;
}