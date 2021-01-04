class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() <= 2) return;

        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> points;

        for (int i = 1; i < m - 1; ++i) {
        	for (int j = 1; j < n - 1; ++j) {
        		vector<vector<bool>> visited(m, vector<bool>(n, false));
        		bool jump = false;
        		dfs(board, visited, points, m, n, i, j, jump);
        		for (auto [x, y]: points) board[x][y] = 'X';
        	}
        }
    }

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited,
    	vector<pair<int, int>> &points, int m, int n, int i, int j, bool &jump) {
    	if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' || jump) return;
    	if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O') {
    		points.clear(); jump = true;
    		return;
    	}
    	if (!visited[i][j]) {
			points.push_back({i, j});
			visited[i][j] = true;
			dfs(board, visited, points, m, n, i-1, j, jump);
			dfs(board, visited, points, m, n, i+1, j, jump);
			dfs(board, visited, points, m, n, i, j-1, jump);
			dfs(board, visited, points, m, n, i, j+1, jump);
    	}
    }
};
