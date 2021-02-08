/*
	[[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]

	[[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]

	result = []
	iteration 1: result = [[6,0]]
	iteration 2: result = [[5,0], [6,0]]
	iteration 3: result = [[4,0], [5,0], [6,0]]
	iteration 4: result = [[4,0], [5,0], [3,2], [6,0]]
	iteration 5: result = [[4,0], [5,0], [2,2], [3,2], [6,0]]
	iteration 6: result = [[4,0], [5,0], [2,2], [3,2], [1,4], [6,0]]


	[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]

	[[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]

	result = []
	iteration 1: result = [[7,0],[7,1]]
	iteration 2: result = [[7,0],[6,1],[7,1]]
	iteration 3: result = [[5,0],[7,0],[5,2],[6,1],[7,1]]
	iteration 4: result = [[5,0],[7,0],[5,2],[6,1],[4,4][7,1]]
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    	sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
    		return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    	});

    	vector<vector<int>> result;
    	for (auto hk: people) {
    		auto loc = result.begin() + hk[1];
    		result.insert(loc, hk);
    	}
    	return result;
	}
};

