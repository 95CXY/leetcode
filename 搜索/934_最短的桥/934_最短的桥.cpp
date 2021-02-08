class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
    	int m = A.size(), n = A[0].size();
    	queue<pair<int, int>> points;

    	int flip = false;
    	for (int i = 0; i < m; ++i) {
    		if (flip) break;
    		for (int j = 0; j < n; ++j) {
    			if (A[i][j] == 1) {
    				dfs(A, points, m, n, i, j);
    				flip = true;
    				break;
    			}
    		}
    	}

    	// 广度优先搜索
    	vector<int> direction{-1, 0, 1, 0, -1};
    	int level = 0, x, y;
    	while (!points.empty()) {
    		++level;
    		int n_points = points.size();
    		while (n_points--) {
	    		auto [r, c] = points.front();
	    		points.pop();

	    		for (int k = 0; k < 4; ++k) {
	    			x = r + direction[k], y = c + direction[k+1];
	    			if (x >= 0 && x < m && y >= 0 && y < n) {
	    				if (A[x][y] == 1) return level;
	    				if (A[x][y] == 2) continue;
	    				
    					points.push({x, y});
    					A[x][y] = 2;
	    			}
	    		}
    		}
    	}
    	return 0;
    }

    void dfs(vector<vector<int>> &A, queue<pair<int, int>> &points, int m, int n, int r, int c) {
    	if (r < 0 || r >= m || c < 0 || c >= n || A[r][c] == 2) return;

    	if (A[r][c] == 0) {
    		points.push({r, c});
    		return;
    	}
    	A[r][c] = 2;
		dfs(A, points, m, n, r + 1, c);
		dfs(A, points, m, n, r - 1, c);
		dfs(A, points, m, n, r, c + 1);
		dfs(A, points, m, n, r, c - 1);
    }
};