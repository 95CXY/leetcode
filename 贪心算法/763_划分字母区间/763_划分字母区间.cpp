class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> stopIndexTable;  // 保存字符最后一次出现的索引
        for (int i = 0; i < S.size(); i++) {
            stopIndexTable[S[i]] = i;
        }

        vector<int> ans;
        int start = 0, stop = stopIndexTable[S[0]];
        
        for (int i = 0; i < S.size(); i++) {
            stop = max(stopIndexTable[S[i]], stop);
            
            if (i == stop) {
                ans.push_back(stop - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};