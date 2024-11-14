#include <iostream>
#include "lengthOfLongestSubstring.cpp"

using std::cout;
using std::endl;

int main() {
    Solution solution;
    string s = "abcabcbb";

    cout << solution.lengthOfLongestSubstring(s) << endl;

    return 0;
}