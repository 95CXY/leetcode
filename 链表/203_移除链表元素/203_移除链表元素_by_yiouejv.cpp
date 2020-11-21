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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode* preNode = head;

        // 特别处理头指针是待被删除元素的情况
        while (preNode != NULL && preNode->val == val) {
            preNode = head->next;
            head->next = NULL;
            delete head;
            head = preNode;
        }
        if (preNode == NULL) return NULL;
        ListNode* curNode = preNode->next;

        // 循环判断后面的节点元素是否是被删除元素
        while (curNode != NULL) {

            if (curNode->val == val) {
                ListNode* waitDelete = curNode;
                preNode->next = curNode->next; 
                curNode = curNode->next;

                waitDelete->next = NULL;
                delete waitDelete;
            }else {
                preNode = curNode;
                curNode = curNode->next;
            }

        }
        return head;
    }
};