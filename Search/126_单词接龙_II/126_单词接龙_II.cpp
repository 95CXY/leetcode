class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	if (wordList.empty() || beginWord.empty() || endWord.empty()) return {};
    	vector<vector<string>> ans;
    	vector<string> path;
    	path.push_back(beginWord);

    	vector<bool> visited(wordList.size(), false);
    	backtracking(beginWord, endWord, wordList, path, ans, visited);
    	return ans;
    }

    void backtracking(const string &beginWord, const string &endWord, vector<string>& wordList,
    	vector<string> &path, vector<vector<string>> &ans, vector<bool> &visited) {

    	if (beginWord == endWord) {
    		while (!ans.empty() && (*(ans.end()-1)).size() > path.size()) ans.pop_back();
			if (ans.empty() || path.size() <= ans[0].size()) ans.push_back(path);
    		return;
    	}

    	auto f = [](const string &a, const string &b){
    		int n = a.size() - b.size();
    		if (n > 1) return false;
    		int count = 0;
    		if (n == 1) count = 1;

    		int len = min(a.size(), b.size());
    		for (int i = 0; i < len; ++i) {
    			if (a[i] != b[i]) ++count;
    			if (count > 1) return false;
    		}
    		return true;
    	};

    	for (int i = 0; i < wordList.size(); ++i) {
    		if (!visited[i] && f(beginWord, wordList[i])) {  // 只相差一个字符
    			path.push_back(wordList[i]); visited[i] = true;
    			backtracking(wordList[i], endWord, wordList, path, ans, visited);
    			path.pop_back(); visited[i] = false;
    		}
    	}
    }
};