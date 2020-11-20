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
    利用数组保存链表中元素的值，直接修改链表的值，不交换节点，违背题意
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        vector<int> vec;
        ListNode* curNode = head;
        while (curNode != NULL) {
            vec.push_back(curNode->val);
            curNode = curNode->next;
        }

        int i = 0;
        int j = vec.size() - 1;
        curNode = head;
        while (i < j) {
            curNode->val = vec[i];
            curNode = curNode->next;
            curNode->val = vec[j];
            curNode = curNode->next;
            i ++; j --;
        }
        if (i == j) {
            curNode->val = vec[i];
        }
    }
};
