class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    	if (matrix.empty() || matrix[0].empty()) return {};
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int>> ans;
		vector<vector<bool>> can_reach_p(row, vector<bool>(col, false));
		vector<vector<bool>> can_reach_a(row, vector<bool>(col, false));

		for (int i = 0; i < row; ++i) {
			dfs(matrix, can_reach_p, i, 0);
			dfs(matrix, can_reach_a, i, col-1);
		}

		for (int i = 0; i < col; ++i) {
			dfs(matrix, can_reach_p, 0, i);
			dfs(matrix, can_reach_a, row-1, i);
		}

		for (int r = 0; r < row; ++r) {
			for (int c = 0; c < col; ++c) {
				if (can_reach_p[r][c] && can_reach_a[r][c]) {
					ans.push_back(vector<int>{r, c});
				}
			}
		}
		return ans;
    }

    void dfs(vector<vector<int>> &matrix, vector<vector<bool>>& can_reach, int r, int c) {
		if (can_reach[r][c]) return;
		can_reach[r][c] = true;

		int row = matrix.size(), col = matrix[0].size();
		if (r + 1 < row && c >= 0 && matrix[r][c] <= matrix[r+1][c]) {
			dfs(matrix, can_reach, r+1, c);
		}
		if (r - 1 >= 0 && c >= 0 && matrix[r][c] <= matrix[r-1][c]) {
			dfs(matrix, can_reach, r-1, c);
		}
		if (r >= 0 && c + 1 < col && matrix[r][c] <= matrix[r][c+1] ) {
			dfs(matrix, can_reach, r, c+1);
		}
		if (r >= 0 && c - 1 >= 0 && matrix[r][c] <= matrix[r][c-1]) {
			dfs(matrix, can_reach, r, c-1);
		}
    }
};