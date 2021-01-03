class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	if (board.empty() || board[0].empty()) return false;
    	int row = board.size(), col = board[0].size();

    	bool find = false;
		vector<vector<bool>> visited(row, vector<bool>(col, false));
    	for (int r = 0; r < row; ++r) {
    		for (int c = 0; c < col; ++c) {
    			backtracking(board, word, visited, find, r, c, 0);
    		}
    	}
    	return find;
    }

    void backtracking(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, bool &find, int r, int c, int index) {
		if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return;
		if (board[r][c] != word[index] || visited[r][c] || find) return;
		if (index == word.size() - 1) {
			find = true;
			return;
		}

		visited[r][c] = true;
		backtracking(board, word, visited, find, r+1, c, index+1);
		backtracking(board, word, visited, find, r-1, c, index+1);
		backtracking(board, word, visited, find, r, c+1, index+1);
		backtracking(board, word, visited, find, r, c-1, index+1);
		visited[r][c] = false;
    }
};