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
// Author: yiouejv
// Email: yiouejv@126.com
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p1 = head;  // 奇数链
        ListNode* p2 = head->next;  // 偶数链
        ListNode* p = head->next->next;

        ListNode* cur1 = p1;
        ListNode* cur2 = p2;
        int flag = 1;
        while (p != NULL) {
           if (flag == 1) {
               cur1->next = p;
               cur1 = p;
               flag = 0;
           }else {
               cur2->next = p;
               cur2 = p;
               flag = 1;
           }
           p = p->next;
        }
        cur2->next = NULL;
        cur1->next = p2;
        return p1;
    }
};