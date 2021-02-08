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

        int value = head->val;
        int valueCount = 1;
        ListNode* ans = NULL;
        ListNode* ansCurNode = ans;
        ListNode* curNode = head->next;
        
        while (curNode != NULL) {
            if (curNode->val != value) {
                if (valueCount == 1) {
                    ListNode* node = new ListNode(value);
                    if (ans == NULL) {
                        ans = node;
                        ansCurNode = ans;
                    }else {
                        ansCurNode->next = node;
                        ansCurNode = node;
                    }
                }
                value = curNode->val;
                valueCount = 1;
            }else {
                valueCount ++;
            }
            curNode = curNode->next;
        }
        if (valueCount == 1) {
            if (ans == NULL) return new ListNode(value);
            ListNode* node = new ListNode(value);
            ansCurNode->next = node;
        }
        return ans;
    }
};