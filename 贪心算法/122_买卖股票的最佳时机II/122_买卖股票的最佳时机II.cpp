// 实际上就是取后一个数减前一个数的累加和

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.empty() || prices.size() == 1) return 0;

        int ans = 0;
        for (int i = 1; i < prices.size(); i ++) {
    		if (prices[i] > prices[i-1]) {
    			ans += (prices[i] - prices[i-1]);
    		}
        }
        return ans;
    }
};