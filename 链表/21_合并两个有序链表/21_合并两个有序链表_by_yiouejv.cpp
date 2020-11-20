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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* ans = NULL;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* ansCurNode = ans;

        while (p1 != NULL && p2 != NULL) {
            ListNode* node = NULL;
            if (p1->val < p2->val) {
                node = new ListNode(p1->val);
                p1 = p1->next;
            }else {
                node = new ListNode(p2->val);
                p2 = p2->next;
            }

            if (ans == NULL) {
                ans = node;
                ansCurNode = ans;
            }else {
                ansCurNode->next = node;
                ansCurNode = node;
            }
        }

        ansCurNode->next = p2 ? p2 : p1;
        return ans;
    }
};