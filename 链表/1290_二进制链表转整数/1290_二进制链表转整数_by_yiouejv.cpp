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
/*
	二进制的本质: 左移一位+当前值
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;

        ListNode* p = head;
        while (p != NULL) {
            ret = (ret << 1) + p->val;
            p = p->next;
        }

        return ret;
    }
};