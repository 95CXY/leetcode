/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * Author: yiouejv
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        string ans("");
        int i = 0;
        int j = 0;
        unordered_map<char, int> hashtable;
        vector<int> isView(s.size(), 0);
        for (auto iter=t.begin(); iter!=t.end(); iter++) hashtable[*iter] ++;
        
        while (i < s.size() && j < s.size())
        {
            if (isView[j] == 0 && hashtable.count(s[j]) == 1) {
                hashtable[s[j]] --;
                isView[j] = 1;
            }
            if (!isZero(hashtable)) {
                j++;
            } else  {
                if (ans == "" || ans.size() > j - i + 1) ans.assign(s, i, j-i+1);
                if (hashtable.count(s[i])==1) {
                    hashtable[s[i]] ++;
                }
                i++;
            }
        }
        return ans;
    }

    inline bool isZero(unordered_map<char, int> & hashtable)
    {
        bool ret = true;
        for (auto iter=hashtable.begin(); iter!=hashtable.end(); iter++)
        {
            if (iter->second > 0) {
                ret = false;
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

