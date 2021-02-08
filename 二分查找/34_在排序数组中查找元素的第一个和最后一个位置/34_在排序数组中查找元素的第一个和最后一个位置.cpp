class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	if (nums.size() == 0) return vector<int>{-1, -1};
    	int l = 0, r = nums.size(), mid;

    	while (l < r) {
    		mid = l + (r - l) / 2;
    		if (nums[mid] == target) {
    			int start = mid, stop = mid;
    			while (start >= 0 && nums[start] == target) --start;
				while (stop < nums.size() && nums[stop] == target) ++stop;
				return vector<int>{++start, --stop};
    		}else if (nums[mid] > target) {
    			r = mid;
    		}else {
    			l = mid + 1;
    		}
    	}
    	return vector<int>{-1, -1};
    }
};