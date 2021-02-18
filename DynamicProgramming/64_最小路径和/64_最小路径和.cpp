/////////////////////////////////////////////////////////////////
// 二维数组 dp 记录走到当前位置的最小值
// 当前位置的最小值 = 当前位置的值 +
// 如果上面和左边同时有元素，则 加上其中一个较小的值
// 否则只加其中一个元素的值
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i][j] = grid[i][j];
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                }else {
                    if (i - 1 >= 0) dp[i][j] += dp[i-1][j];
                    if (j - 1 >= 0) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

////////////////////////////////////////////////////////
// 空间压缩
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int left = 0, cur;
        vector<int> tops(n, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cur = grid[i][j];
                if (i - 1 >= 0 && j - 1 >= 0) {
                    cur += min(tops[j], left);
                }else {
                    if (i - 1 >= 0) {
                        cur += tops[j];
                    }
                    if (j - 1 >= 0) {
                        cur += left;
                    }
                }
                tops[j] = cur;
                left = cur;
            }
        }
        return cur;
    }
};