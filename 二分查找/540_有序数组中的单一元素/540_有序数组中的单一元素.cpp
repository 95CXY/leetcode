class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	int l = 0, r = nums.size() - 1, mid;
    	while (l < r) {
    		mid = l + (r - l) / 2;
    		if (mid == l) break;
    		if ((mid - l) % 2) {  // 奇数
    			if (nums[mid] == nums[mid-1]) l = mid + 1;
    			else r = mid;
    		}else {
    			if (nums[mid] == nums[mid-1]) r = mid - 1;	
    			else l = mid;
    		}

    	}
    	return nums[l];
    }
};