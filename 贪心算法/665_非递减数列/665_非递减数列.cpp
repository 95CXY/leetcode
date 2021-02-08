/*
	[5,7,1,8]

	5,7,7,8

	[4,2,3]

	2,2,3   4,4,3

	[3,4,2,3]

	3,2,2,3

	[1,2,4,5,3]


*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    	int count = 0, length = nums.size();
    	for (int i = 1; i < length; i++) {
    		if (nums[i] < nums[i-1]) {
    			count++;
    			if (count > 1) return false;
    			if (i+1 >= length || nums[i+1] >= nums[i-1]) {
    				nums[i] = nums[i-1];
    			}else {
    				nums[i-1] = nums[i];
    				if (i-2 >= 0 && nums[i-2] > nums[i-1]) return false;
    			}
    		}
    	}
    	return count <= 1;
    }
};