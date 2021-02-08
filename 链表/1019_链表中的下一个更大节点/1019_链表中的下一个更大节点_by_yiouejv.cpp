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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* cur = head;
        while (cur != NULL) {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        vector<int> ans(arr.size(), 0);
        stack<int> s;

        for (int j = arr.size() - 1; j >= 0; j --) {
            while (!s.empty() && s.top() <= arr[j]) s.pop();
            ans[j] = !s.empty() ? s.top() : 0;
            s.push(arr[j]);
        }
        return ans;
    }
};