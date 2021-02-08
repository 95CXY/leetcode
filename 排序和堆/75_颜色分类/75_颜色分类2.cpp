class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int length = nums.size();
    	int zero = 0, one = 0, two = 0;

    	for (int n : nums) {
    		if (n == 0) ++zero;
    		else if (n == 1) ++one;
    		else if (n == 2) ++two;
    	}

    	int i = 0;
    	while (i < length) {
    		if (zero-- > 0) nums[i++] = 0;
    		else if (one-- > 0) nums[i++] = 1;
    		else if (two-- > 0) nums[i++] = 2;
    		else break;
    	}
    }
};