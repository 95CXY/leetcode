class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tTable;
        vector<int> isView(s.size(), 0);

        for (char c: t) ++tTable[c];
        string ans;
        int i = 0, j = 0;
        while (i <= j && j < s.size()) {
            if (isView[j] == 0 && tTable.count(s[j])) {
               --tTable[s[j]]; isView[j] = 1;
            }
            if (isAllZero(tTable)) {
                if (ans.empty() || ans.size() > j-i+1) ans.assign(s.begin()+i, s.begin()+j+1);
                if (tTable.count(s[i])) ++tTable[s[i]];
                ++i;
            }else {
                ++j;
            }
        }
        return ans;
    }

    bool isAllZero(unordered_map<char, int> &tTable) {
        for (auto iter: tTable) {
            if (iter.second > 0) return false;
        }
        return true;
    }
};