#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    void printList(ListNode *head)
    {
        while (head != nullptr)
        {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    ListNode *getMid(ListNode *head)
    {
        // 快慢指针法，寻找链表中间节点
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        // std::cout << "Before merge:" << std::endl;
        // std::cout << "list1: " << std::endl;
        // printList(list1);
        // std::cout << "list2: " << std::endl;
        // printList(list2);

        ListNode *dummy, *tail;
        dummy = tail = new ListNode();
        while ( list1 != nullptr && list2 != nullptr )
        {
           if (list1->val < list2->val) {
               tail->next = list1;
               list1 = list1->next;
           } else {
               tail->next = list2;
               list2 = list2->next;
           }
           tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        } 

        if (list2 != nullptr) {
            tail->next = list2;
        }

        // // 打印后并后的链表
        // std::cout << "After merge:" << std::endl;
        // printList(dummy->next);
        return dummy->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        // 处理空链表与单个节点的特殊情况
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *left = head;
        // 获取中点
        ListNode *mid = getMid(head);
        ListNode *right = mid->next;
        mid->next = nullptr;

        // 递归划分
        // sortList(left);
        // sortList(right);
        left = sortList(left);
        right = sortList(right);

        // 合并
        return merge(left, right);
    }
};