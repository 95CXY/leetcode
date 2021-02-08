class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        dfs(nums, ans, path, used, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, vector<bool>& used, int depth)
    {
        if (nums.size() == depth)
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, ans, path, used, depth+1);
                used[i] = false;
                path.pop_back();
            }
        }
    }
}; 