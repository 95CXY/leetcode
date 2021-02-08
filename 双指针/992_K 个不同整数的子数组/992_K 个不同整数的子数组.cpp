// Author: yiouejv
// Email: yiouejv@126.com

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int i = 0;
        int j = 0;
        int ans = 0;

        unordered_map<int, int> hashtable;
        while (i < A.size() - K + 1) {
            if (j < A.size()) hashtable[A[j]] ++;
            if (j < A.size() && hashtable.size() < K) {
                j++;
            } else if (j < A.size() && hashtable.size() == K) {
                ans++; j++;
            } else {
                i++; j = i;
                hashtable.clear();
            }
        }
        return ans;
    }
};