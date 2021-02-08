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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
            if (curA == NULL && curB != NULL) {
                curA = headB;
            }

            if (curB == NULL && curA != NULL) {
                curB = headA;
            }
        }
        return curA;
    }
};