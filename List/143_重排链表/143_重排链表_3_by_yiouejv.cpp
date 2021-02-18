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

/*
    反转链表, 遍历原链表和反转链表，遍历到中间停止
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        int length = 0;
        ListNode* p = head;
        while (p != NULL) {
            p = p->next;
            length ++;
        }
        
        ListNode* curHeadNode = head;
        ListNode* ans = NULL;
        ListNode* ansCurNode = NULL;
        ListNode* reversedHead = reversed(head);

        for (int i = 0; i < length / 2; i++) {
            ListNode* node = new ListNode(curHeadNode->val);
            curHeadNode = curHeadNode->next;
            ListNode* node2 = new ListNode(reversedHead->val);
            reversedHead = reversedHead->next;

            node->next = node2;
            if (ans == NULL) {
                ans = node;
            }else {
                ansCurNode->next = node;
            }
            ansCurNode = node2;
        }
        if (length % 2 == 1) {
            ansCurNode->next = new ListNode(curHeadNode->val);
        }
        *head = *ans;
    }

    ListNode* reversed(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* curNode = head;
        while (curNode != NULL) {
            ListNode* node = new ListNode(curNode->val);
            node->next = ans;
            ans = node;
            curNode = curNode->next;
        }
        return ans;
    }
};
