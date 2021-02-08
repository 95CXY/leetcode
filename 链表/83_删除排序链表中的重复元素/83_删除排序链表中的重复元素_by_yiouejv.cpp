/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Author: yiouejv
//Email: yiouejv@126.com

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        int temp = head->val;
        ListNode* ans = new ListNode(head->val);
        ListNode* ansCurNode = ans;
        ListNode* curNode = head->next;
        
        while (curNode != NULL) {
            if (curNode->val != temp) {
                temp = curNode->val;
                ListNode* node = new ListNode(temp);
                ansCurNode->next = node;
                ansCurNode = node;
            }
            curNode = curNode->next;
        }
        return ans;
    }
};