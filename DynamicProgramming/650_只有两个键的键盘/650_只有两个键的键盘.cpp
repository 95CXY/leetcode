class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = i;
            for (int j = 2; j <= i; ++j)
            {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i/j];
                }
            }
        }
        return dp[n];
    }
};