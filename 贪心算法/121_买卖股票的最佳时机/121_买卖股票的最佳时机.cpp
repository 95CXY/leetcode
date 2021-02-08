class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.empty()) return 0;
    	int ans = 0, p = prices[0];
    	for (int i = 1; i < prices.size(); i++) {
    		p = min(p, prices[i]);
    		ans = max(ans, prices[i] - p);
    	}
    	return ans;
    }
};