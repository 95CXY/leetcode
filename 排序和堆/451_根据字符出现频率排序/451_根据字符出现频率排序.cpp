class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char, int> counts;
    	for (char c: s) ++counts[c];

		auto cmp = [](pair<char, int> a, pair<char, int> b){
			return a.second < b.second;
		};
		priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> heap(cmp);
		for (auto &iter: counts) heap.push(iter);
		string ans;
		while (!heap.empty()) {
			auto p = heap.top();
			heap.pop();
			ans.append(p.second, p.first);
		}
		return ans;
    }
};