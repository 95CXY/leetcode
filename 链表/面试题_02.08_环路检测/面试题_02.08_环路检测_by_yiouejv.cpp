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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return NULL;
        ListNode* p1 = head->next;
        ListNode* p2 = head->next->next;
        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 != NULL) p2 = p2->next;
        }
        if (p1 == NULL) return NULL;  // p1遍历到链表尾部，p1, p2都没相遇，无环

        // 判断环的长度
        int circleLength = 1;
        p1 = p1->next;
        while (p1 != p2) {
            p1 = p1->next;
            circleLength ++;
        }

        // 再利用两个指针找到环的入口点
        p1 = head;
        p2 = head;
        for (int i=0; i<circleLength; i++) {
            p1 = p1->next;
            if (p1 == NULL) return NULL;  // 针对本题需要写，pos没办法保证
        }
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == NULL || p2 == NULL) return NULL;  // 针对本题需要写，pos没办法保证
        }
        return p1;
    }
};