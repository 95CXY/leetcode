class Solution {
public:
    void sortColors(vector<int>& nums) {
    	unordered_map<int, int> counts;
    	for (int n : nums) ++counts[n];

		vector<int> vec;
		for (auto iter: counts) vec.push_back(iter.first);
		sort(vec.begin(), vec.end());
	
		int offset = 0;
		for (int n : vec) {
			int count = counts[n];
			for (int i = offset; i < count + offset; ++i) {
				nums[i] = n;
			}
			offset += count;
		}
    }
};