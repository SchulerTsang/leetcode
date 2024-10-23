#include <iostream>
#include "sortlist.cpp"

using std::cout;
using std::endl;

int main()
{
    ListNode *head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));

    Solution s;
    ListNode *res = s.sortList(head);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    
    return 0;
}