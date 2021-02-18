class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    	if (n <= 0) return {};
    	vector<vector<string>> ans;
    	vector<string> slove(n, string(n, '.'));
    	vector<pair<int, int>> path;
    	backtracking(n, ans, slove, path, 0);
    	return ans;
    }

    void backtracking(int n, vector<vector<string>> &ans, vector<string> &slove, vector<pair<int, int>> &path, int level) {
    	if (level == n) {
    		ans.push_back(slove);
    		return;
    	}

		for (int j = 0; j < n; ++j) {
			// 验证该点是否可放
			bool jump = false;
	    	for (auto pos: path) {
	    		int r = pos.first, c = pos.second;
	    		if (c == j) {  // 竖方向	
	    			jump = true; break;
	    		}
    			// 斜方向
    			int nextR = r, nextCLeft = c, nextCRight = c;
    			while (nextR <= level && nextR < n) {
    				++nextR; --nextCLeft; ++nextCRight;
    				if (nextR == level && (nextCLeft == j || nextCRight == j)) {
    					jump = true; break;
    				}
    			}
	    	}
	    	if (jump) continue;
			slove[level][j] = 'Q'; path.push_back({level, j}); 
			backtracking(n, ans, slove, path, level+1);
			slove[level][j] = '.'; path.pop_back();
		}
    }
};
