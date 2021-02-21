/*
    动态规划的0-1背包问题: 根据题意，我们要将数组分割成两个子集，使得两个子集的元素和相等，
    就说明单个子集的元素和为原数组的和的一半（target），我们可以把target看成是背包的容量，
    每一个元素则为可以放进背包的物品的大小;

    声明一个矩阵dp, dp[i][j] 表示遍历到第i个物品，背包容量为j时可以放进背包的物品的总大小，
    对于d[i][j]，我们可以选择在此时不放入当前的物品，则背包的物品的总大小为d[i-1][j]，也就是
    遍历到上一个物品时背包放入物品的大小，第二个选择是放入当前的物品，此时背包的物品的总大小为
    上一个物品，背包容量为 j - 当前物品大小（要保证能放进现在的物品）+ 物品的大小，为
    dp[i-1][j-nums[i]] + nums[i]; 取其中一个最大值就是此时能放进物品的总和最大值。

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
                1   2   3   4   5   6   7   8   9   10  11
                __________________________________________
            1  |1   1   1   1   1   1   1   1   1   1   1
            5  |1   1   1   1   5   6   6   6   6   6   6
           11  |1   1   1   1   5   6   6   6   6   6   11
            5  |1   1   1   1   5   6   6   6   6   10  11
        */
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = nums[i-1]; j <= target; ++j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]]+nums[i-1]);
            }
        }
        return dp[n][target] == target;
    }
};

/*
    对空间进行压缩，观察代码发现，我们每次遍历第i行时，只会使用i-1行的数据，前面的数据都将不会再使用，
    可以使用一维数组保存背包所装物品的大小。 这时我们遍历每一行的时候必须反向遍历，否则你会发现，dp[j-w]
    的值在遍历到j之前就已经被改变成i的值了。

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = target; j >= nums[i-1]; --j)
            {
                dp[j] = max(dp[j], dp[j-nums[i-1]]+nums[i-1]);
            }
        }
        return dp[target] == target;
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));
        for (int i = 0; i <= n; ++i)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = nums[i-1]; j <= target; ++j)
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = target; j >= nums[i-1]; --j)
            {
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[target];
    }
};