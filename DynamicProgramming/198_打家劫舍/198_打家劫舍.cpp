////////////////////////////////////////////////////////
// 当前能偷到的最大值为 dp[i-2] + nums[i-1],  当前这家不偷，所能偷到的值为dp[i-1]
// 与往前数两家 + 当前这家所能偷盗的值 取 最大值
// 得到状态转移方程: dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
// 注意: dp 与 nums 的下标相差一位
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
};

///////////////////////////////////////////////
// 空间压缩
// 只需要保存前一家和前两家的值
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int i2 = 0, i1 = nums[0], cur;
        for (int i = 2; i <= n; ++i)
        {
            cur = max(i2+nums[i-1], i1);
            i2 = i1;
            i1 = cur;
        }
        return cur;
    }
};