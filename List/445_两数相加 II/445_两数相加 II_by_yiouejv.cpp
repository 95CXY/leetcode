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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        vector<int> vec1;
        vector<int> vec2;
        
        while (cur1 != NULL) {
            vec1.push_back(cur1->val);
            cur1 = cur1->next;
        }
        while (cur2 != NULL) {
            vec2.push_back(cur2->val);
            cur2 = cur2->next;
        }

        ListNode* ans = NULL;
        int i = vec1.size() - 1;
        int j = vec2.size() -1;
        int n = 0;  // 表示进位的值

        while (i >= 0 && j >= 0) {
            int m = vec1[i] + vec2[j] + n;
            
            if (m >= 10) {
                m %= 10;
                n = 1;
            }else {
                n = 0;
            }
            AddToHead(ans, m);
            i--; j--;
        }
        while(i >= 0) {
            if (n == 1) {
                int m = vec1[i--] + 1;
                if (m >= 10) {
                    m %= 10;
                }else {
                    n = 0;
                }
                AddToHead(ans, m);
            }else {
                AddToHead(ans, vec1[i--]);
            }
        }
        while(j >= 0) {
            if (n == 1) {
                int m = vec2[j--] + 1;
            
                if (m >= 10) {
                    m %= 10;
                }else {
                    n = 0;
                }
                AddToHead(ans, m);
            }else {
                AddToHead(ans, vec2[j--]);
            }
        }
        if (n == 1) AddToHead(ans, 1);
        return ans;
    }

    void AddToHead(ListNode*& head, int i) {
        ListNode* p = new ListNode(i);
        p->next = head;
        head = p;
    }
};