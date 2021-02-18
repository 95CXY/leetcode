class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0) return {};
        vector<vector<int>> ans;
        for (int i = 1; i <= n; ++i) {
            vector<int> path;
            path.push_back(i);
            backtracking(ans, path, n, k, 1);
        }
        return ans;
    }

    void backtracking(vector<vector<int>>& ans, vector<int> &path, int n, int k, int level) {
        if (level == k) {
            ans.push_back(path);
            return;
        }
        for (int i = path.back()+1; i <= n; ++i) {
            path.push_back(i);
            backtracking(ans, path, n, k, level+1);
            path.pop_back();
        }
    }
};