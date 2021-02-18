/*
 * @lc app=leetcode.cn id=986 lang=cpp
 * Author: yiouejv
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;

        while (i < A.size() && j < B.size())
        {
            int s1 = A[i][0];
            int e1 = A[i][1];
            int s2 = B[j][0];
            int e2 = B[j][1];

            if (e1 < s2) i++;
            else if(e2 < s1) j++;
            else
            {
                vector<int> temp;
                int lower = max(s1, s2);
                int height = min(e1, e2);
                if (lower <= height)
                {
                    temp.push_back(lower);
                    temp.push_back(height);
                    ans.push_back(temp);
                }
                if (e1 < e2) i++;
                else j++;
            }
            
        }
        return ans;
    }
};
// @lc code=end

