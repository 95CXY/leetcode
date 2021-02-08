/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * Autohr: yiouejv
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int i = 0;
        int j = 0;

        while (j < haystack.size())
        {
            if (haystack[i] == needle[0])
            {
                auto iter=needle.begin();
                for (; iter!=needle.end(); iter++)
                {
                    if (j >= haystack.size()) return -1;
                    if (haystack[j] != *iter)
                    {
                        i++; j=i; break;
                    }
                    else j++;
                }
                if (iter == needle.end() && j - i == needle.size()) return i;
            }
            else
            {
                i++; j++;
            }
        }
        return -1;
    }
};
// @lc code=end

