/*
    先每个人分一个糖果，保证每个人先有一个。
    从左往右遍历，如果右孩子比左孩子评分高，则右孩子的糖果 = 左孩子糖果 + 1
    从右往左遍历，如果左孩子比右孩子评分高，则左孩子的糖果 = max(右孩子糖果+1, 左孩子的糖果)
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> ans;
        for (int i: ratings) {
            ans.push_back(1);
        }

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                ans[i] = ans[i-1] + 1;
            }
        }
        
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                ans[i - 1] = max(ans[i] + 1, ans[i - 1]);
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};