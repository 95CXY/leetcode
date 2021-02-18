/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	if (!head || !head->next || !head->next->next) return NULL;
        ListNode *slow = head->next, *quick = head->next->next;
        while (slow != quick) {
        	if (!quick || !quick->next) return NULL;
        	slow = slow->next;
        	quick = quick->next->next;
        }

        slow = head;
        while (slow != quick) {
        	slow = slow->next;
        	quick = quick->next;
        }
        return slow;
    }
};