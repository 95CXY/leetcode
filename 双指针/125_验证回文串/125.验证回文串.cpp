/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * Author: yiouejv
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 ) return true;
        int i = 0;
        int j = s.size() - 1;
        while (i < j && j < s.size())
        {
            while (i < j && !istarget(s[i])) {
                i++;
            }
            while (i < j && !istarget(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])){
                return false;
            }
            if (i == j) return true;
            i++; j--;
        }
        return true;
    }

    template<typename T>
    inline bool istarget(T s)
    {
        if (isalpha(s) || isdigit(s)) return true;
        return false;
    }
};
// @lc code=end

