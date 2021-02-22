class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    dp[i][j] = j;
                }
                else if (j == 0) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = min(dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1),
                        min(dp[i-1][j], dp[i][j-1]) + 1);
                }
            }
        }
        return dp[m][n];
    }
};