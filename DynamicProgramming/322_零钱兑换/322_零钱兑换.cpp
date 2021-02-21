/**
 * @authors yiouejv
 * @email yiouejv@126.com
 * @date 2021-02-21 22:10:16
 * @version 1.0
 **/
/*
    定义一个dp数组，背包容量为 amount+1, 初始化为 amount+1, 为什么不是-1？
    因为题目要求的是最少硬币的数量，所以如果 amount 如果满足条件的结果最大为 amount, 取 amount + 1 一定大于所有的组合
    dp数组的长度为 amount+1, 所以 amount+1的硬币满足条件最大为 amount + 1, 所以我们取 amount + 2,
    对于每一个位置，当前位置满足条件时的最小数量为min(当前的值和，去掉该coin + 1), 1为多加的一枚硬币
    如果最后结果还是 amount + 2，说明不存在满足条件的组合
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        vector<int> dp(amount+1, amount+2);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int coin: coins) {
                if (i >= coin)
                {
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        return dp[amount] == (amount + 2) ? -1 : dp[amount];
    }
};