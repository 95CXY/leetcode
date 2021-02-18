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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* preNode = NULL;
        ListNode* curNode = head;
        ListNode* nextNode = head->next;

        while (curNode != NULL) {
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
            if (curNode != NULL) {
                nextNode = curNode->next;
            }
        }
        return preNode;
    }
};