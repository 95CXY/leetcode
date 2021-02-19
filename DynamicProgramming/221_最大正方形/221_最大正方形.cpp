class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), max_side = 0;
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }
        return max_side * max_side;
    }
};