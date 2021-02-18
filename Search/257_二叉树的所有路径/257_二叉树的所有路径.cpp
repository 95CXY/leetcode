/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> ans;
    	vector<int> path;
    	dfs(root, ans, path);
    	return ans;
    }

    void dfs(const TreeNode* root, vector<string> &ans, vector<int> &path) {
    	if (root != NULL) {
			path.push_back(root->val);
    		if (root->left == NULL && root->right == NULL) {

    			// 拼接成结果
    			string s;
    			for (int i = 0; i < path.size(); ++i) {
    				if (i > 0) s += "->";
					s += to_string(path[i]);
    			}
	    		ans.push_back(s);
				path.pop_back();
	    		return;
    		}
			dfs(root->left, ans, path);
			dfs(root->right, ans, path);
			path.pop_back();
    	}
    }
};