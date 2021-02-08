// Author: yiouejv
// Email: yiouejv@126.com

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> hashtable;
        int i = 0;
        int j = 0;
        long _sum = 0;
        int ret = INT_MAX;
        hashtable[0] = -1;

        for (auto a: nums) _sum += (a % p);
        int r0 = _sum % p;
        if (r0 == 0) return 0;

        long _prefixSumJ = 0;
        for (; j < nums.size(); j++) {
            _prefixSumJ += (nums[j] % p);
            int r = _prefixSumJ % p;
            int n = (r - r0) >= 0 ? (r - r0) : (r - r0 + p);
            if (hashtable.find(n) != hashtable.end()) {
                i = hashtable[n] + 1;
                ret = min(ret, j-i+1);
            }
            hashtable[r] = j;
        }

        if (ret >= nums.size()) return -1;
        return ret;
    }
};