class Solution {
public:
    int climbStairs(int n) {
        map<int, int> record;
        record[1] = 1;
        record[2] = 2;
        return helper(n, record);
    }

    int helper(int n, map<int, int>& record)
    {
        if (record[n]) {
            return record[n];
        }
        else {
            int m = helper(n - 1, record) + helper(n - 2, record);
            record[n] = m;
            return m;
        }
    }
};

//////////////////////////////////////////////////
// dp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);
        for (int i = 2; i < n + 1; ++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


/////////////////////////////////////////////////
// 对dp进行空间压缩
// 只需要保存i-1，i-2处的值
class Solution {
public:
    int climbStairs(int n) {
        int pre1 = 1, pre2 = 1, cur;
        for (int i = 2; i < n + 1; ++i)
        {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};


