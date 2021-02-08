class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	int length = candidates.size();
    	vector<vector<int>> ans;

    	for (int i = 0; i < length; ++i) {
    		if (i == 0 || candidates[i] != candidates[i - 1]) {
	    		vector<int> path{candidates[i]};
	    		int pathSum = candidates[i];
	    		dfs(ans, candidates, target, length, path, pathSum, i);
    		}
    	}
    	return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &candidates, const int target, const int length, vector<int> &path, int pathSum, const int i) {
    	if (pathSum > target) return;
    	if (pathSum == target) {
    		ans.push_back(path);
    		return;
    	}

    	for (int j = i + 1; j < length; ++j) {
    		if (j > i + 1 && candidates[j] == candidates[j - 1]) continue;
    		path.push_back(candidates[j]); pathSum += candidates[j];
    		dfs(ans, candidates, target, length, path, pathSum, j);
    		path.pop_back(); pathSum -= candidates[j];
    	}
    }
};
