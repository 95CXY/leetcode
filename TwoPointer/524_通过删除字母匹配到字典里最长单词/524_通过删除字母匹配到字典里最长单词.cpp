class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;

        for (string word: d) {
            if (isFindWord(s, word)) {
                if (ans.empty() || ans.size() < word.size() || (ans.size() == word.size() && ans > word)) {
                    ans.assign(word);
                }
            }
        }

        return ans;
    }

    bool isFindWord(string &s, string &word) {
        int i = 0, j = 0;
        while (i < word.size() && j < s.size()) {
            if (word[i] == s[j]) {
                ++i; ++j;
            }else ++j;
        }
        return i == word.size();
    }
};