class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char, int> counts;
    	for (char c: s) ++counts[c];
		vector<char> vec;

		for (pair<const char, int> &iter: counts) vec.push_back(iter.first);
		sort(vec.begin(), vec.end(), [counts](char a, char b) {
			return counts.at(a) > counts.at(b);
		});

		string ans;
		for (char c: vec) {
			ans.append(counts[c], c);
		}
		return ans;
    }
};