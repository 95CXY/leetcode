// Author: yiouejv
/*
    滑动窗口，i 窗口左边界，j窗口又边界
    maxLen 窗口中最大相同的值
    (j - i + 1) i到j的长度 - maxLen = 需要替换的个数
    nums 用来记录字母在窗口中出现的次数
*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int maxLen = 0;
        vector<int> nums(256, 0);

        while (j < s.size())
        {
            nums[s[j]] ++;
            maxLen = max(maxLen, nums[s[j]]);
            if (j - i + 1 - maxLen > k)
            {
                nums[ int(s[i]) ] --;
                ans = max(ans, j-i);
                i++;
            }
            j++;
        }
        ans = max(ans, j-i);
        return ans;
    }
};