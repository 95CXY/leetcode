class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n: nums) {
            ++counts[n];
        }

        auto cmp = [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);

        for (auto iter: counts) {
            heap.push(iter);
            if (heap.size() > k) heap.pop();
        }
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};