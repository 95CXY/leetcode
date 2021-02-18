/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordMap;
        for (auto word : words) wordMap[word] ++;
        unordered_map<string, int> wordMapTemp(wordMap);
        
        int i = 0;
        int j = 0;
        vector<int> ans;

        while (j < s.size())
        {
            int nextWordStartIndex = isNext(s, wordMapTemp, j);
            if (nextWordStartIndex != -1)
            {
                j = nextWordStartIndex;
                if (isValueAllZero(wordMapTemp))
                {
                    ans.push_back(i);
                    i++; j=i;
                    wordMapTemp = wordMap;
                }
            }
            else
            {
                i++; j=i;
                wordMapTemp = wordMap;
            }
        }
        return ans;
    }

    int isNext(string& s, unordered_map<string, int>& wordMap, int startIndex)
    {
        int j = startIndex;

        for (auto iter=wordMap.begin(); iter!=wordMap.end(); iter++)
        {
            string word = iter->first;
            if (iter->second > 0 && s[j] == word[0])
            {
                auto it=word.begin();
                for (; it!=word.end(); it++)
                {
                    if (s[j] != *it)
                    {
                        j = startIndex;
                        break;
                    } else j++;
                }
                // 匹配上了
                if (it == word.end() && j-startIndex == word.size())
                {
                    wordMap[word] --;
                    return j;
                }
            }
        }
        return -1;
    }

    bool isValueAllZero(unordered_map<string, int>& wordMap)
    {
        bool ret = true;
        for (auto iter=wordMap.begin(); iter!=wordMap.end(); iter++)
        {
            if (iter->second != 0)
            {
                ret = false; break;
            }
        }
        return ret;
    }
};
// @lc code=end

