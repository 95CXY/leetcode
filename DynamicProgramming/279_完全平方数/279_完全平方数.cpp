/////////////////////////////////
// 分割类型，动态规划的状态转移方程通常不依赖相邻的位置，而是依赖于满足分割条件的位置
// 定义一个一维数组，dp[i]表示数字i最少可以由几个完全平方数相加构成，在本题中，
// 位置i只依赖于i-k^2的位置，如 i-1, i-4, i-9
// 因此dp[i] 的动态转移方程为 dp[i] = 1 + min(dp[i-1], dp[i-4], dp[i-9]...);
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j*j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};