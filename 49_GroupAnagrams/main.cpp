#include <iostream>
#include "groupAnagrams.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    auto ans = solution.groupAnagrams(strs);
    for (auto &v : ans) {
        for (auto &s : v) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}