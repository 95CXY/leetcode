/*
    设一个数组dp，dp[i]表示i结尾处，最长子序列的长度，
    对于每一个位置i，如果之前的某个位置j所对应的数字小于位置i所对应的数字，
    我们可以获得一个以i结尾的，长度为 dp[j] + 1的子序列
    n^2
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), max_length=1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }
};


/*
    方法2： 定义一个数组dp, dp[k]存储长度k+1的最长递增子序列的最后一个数字，
    我们遍历每一个位置i，如果其大于dp内的所有数字，则将其添加到dp的尾部，
    否则，从dp内找到一个大于等于当前数的位置，将nums[i] 替换掉dp内的数
    最后得到的就是最长的子序列
    nlog(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            if (dp.back() < nums[i])
            {
                dp.push_back(nums[i]);
            }else {
                auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
                *itr = nums[i];
            }
        }
        return dp.size();
    }
};