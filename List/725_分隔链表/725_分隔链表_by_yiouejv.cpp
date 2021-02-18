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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length = 0;
        ListNode* p = root;
        while (p != NULL) {
            length ++;
            p = p->next;
        }

        p = root;
        vector<ListNode*> ans;
        if (length < k) {

            while (p != NULL) {
                ans.push_back(new ListNode(p->val));
                p = p->next;
            }
            for (int i=length; i < k; i++) {
                ans.push_back(NULL);
            } 

        }else {
            int n = length % k;
            int count = 0;

            ListNode* head = NULL;
            ListNode* cur = NULL;

            while (p != NULL) {
                ListNode* node = new ListNode(p->val);
                if (head == NULL) {
                    head = node; 
                    cur = node;
                }else {
                    cur->next = node;
                    cur = node;
                }
                count ++; p = p->next;
                int judge_count = (n > 0) ? (length / k + 1) : (length / k);
                if (count == judge_count) {
                    n --;
                    ans.push_back(head);
                    head = NULL; cur = NULL;
                    count = 0;
                }
            }
            
            if (count > 0) ans.push_back(head);
        }
        return ans;
    }
};