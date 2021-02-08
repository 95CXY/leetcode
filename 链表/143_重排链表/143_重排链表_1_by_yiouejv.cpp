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
    1. 用数组保存节点, 利用数组下标取链表节点，再拼凑起来
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        vector<ListNode*> vec;
        ListNode* curNode = head;
        while (curNode != NULL) {
            vec.push_back(curNode);
            curNode = curNode->next;
        }

        int i = 0;
        int j = vec.size() - 1;
        
        while (i < j) {
            vec[i]->next = vec[j];
            vec[j]->next = NULL;
            if (curNode != NULL) {
                curNode->next = vec[i];
            }
            curNode = vec[j];
            i ++; j --;
        }
        if (i == j) {
            curNode->next = vec[j];
            vec[j]->next = NULL;
        }
    }
};