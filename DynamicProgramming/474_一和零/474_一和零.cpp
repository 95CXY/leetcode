/**
 * @authors yiouejv
 * @email yiouejv@126.com
 * @date 2021-02-21 09:10:20
 * @version 1.0
 **/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int good_size = strs.size(), count0 = 0, count1 = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= good_size; ++i)
        {
            // 统计当前字符串中“0”, “1”的个数
            for (char c: strs[i-1])
            {
                if (c == '0')
                {
                    ++count0;
                } else {
                    ++count1;
                }
            }
            for (int j = m; j >= count0; --j)
            {
                for (int k = n; k >= count1; --k)
                {
                    dp[j][k] = max(dp[j][k], dp[j-count0][k-count1]+1);
                }
            }
            count0 = count1 = 0;
        }
        return dp[m][n];
    }
};

