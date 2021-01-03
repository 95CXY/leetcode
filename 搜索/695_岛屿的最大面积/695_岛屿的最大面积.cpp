class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	vector<vector<int>> visited(grid);
    	int ans = 0, row = grid.size(), col = grid[0].size();
    	for (int r = 0; r < row; ++r) {
    		for (int c = 0; c < col; ++c) {
				ans = max(ans, countOne(grid, r, c, visited));
    		}
    	}
    	return ans;
    }


    int countOne(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &visited) {
    	int row = grid.size(), col = grid[0].size();

    	if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == 0 || visited[r][c] == 0) return 0;
    	visited[r][c] = 0;
    	return 1 + countOne(grid, r, c-1, visited) + countOne(grid, r-1, c, visited)
    	+ countOne(grid, r, c+1, visited) + countOne(grid, r+1, c, visited);
    }

};