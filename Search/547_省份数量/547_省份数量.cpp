class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0 || isConnected[0].size() == 0) return 0;
        int ans = 0, n = isConnected.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, i, n, visited);
                ++ans;
            }
        }
        return ans;
    }

    void dfs(const vector<vector<int>> &isConnected, int i, int n, vector<bool> &visited) {
        visited[i] = true;
        for (int k = 0; k < n; ++k) {
            if (!visited[k] && isConnected[i][k] == 1) {
                dfs(isConnected, k, n, visited);
            }
        }
    }

};