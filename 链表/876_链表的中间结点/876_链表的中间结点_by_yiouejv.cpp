/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Author: yiouejv
// Email: yiouejv@126.com

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* quickPointer = head;
        ListNode* slowPointer = head;

        while (quickPointer != NULL && quickPointer->next != NULL) {
            quickPointer = quickPointer->next->next;
            slowPointer = slowPointer->next;
        }
        return slowPointer;
    }
};