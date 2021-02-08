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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        if (k <= 0) return head;
        int length = 0;
        ListNode* curNode = head;
        while (curNode != NULL) {
            length ++;
            curNode = curNode->next;
        }
        k %= length;
        if (k == 0) return head;

        ListNode* slowPointer = head;
        ListNode* quickPointer = head;
        for(int i=0; i < k; i++)
            quickPointer = quickPointer->next;

        while (quickPointer->next != NULL) {
            slowPointer = slowPointer->next;
            quickPointer = quickPointer->next;
        }
        ListNode* ans = slowPointer->next;
        slowPointer->next = NULL;
        quickPointer->next = head;
        return ans;
    }
};