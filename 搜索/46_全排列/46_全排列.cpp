class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	if (nums.empty()) return {};
    	vector<vector<int>> ans;
    	for (int i = 0; i < nums.size() - 1; ++i) {
			backtracking(nums, ans, i);
    	}
    	return ans;
    }

    void backtracking(vector<int> &nums, vector<vector<int>> &ans, int level) {
    	if (level == nums.size() - 1) {

    		ans.push_back(nums);
    		return;
    	}

		ans.push_back(nums);
    	for (int i = level+1; i < nums.size(); ++i) {
    		swap(nums[level], nums[i]);
    		backtracking(nums, ans, level+1);
    		swap(nums[level], nums[i]);
    	}
    }
}; 