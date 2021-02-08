class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	if (nums.size() == 0) return false;
    	if (nums.size() == 1) return nums[0] == target ? true : false;
        int i = 1, length = nums.size();
        for (;i < length; ++i) {
        	if (nums[i-1] == target ) return true;
        	if (nums[i] < nums[i-1]) break;
        }
        return (i == length && nums[i-1] == target)
        ||(i < length && (binarySearch(nums, 0, i-1, target) || binarySearch(nums, i, length-1, target)));
    }

    bool binarySearch(vector<int> &nums, int l, int r, int target) {
    	int mid;
    	while (l < r) {
    		mid = l + (r - l) / 2;
    		if (nums[mid] == target) {
    			return true;
    		}else if (nums[mid] > target) {
    			r = mid;
    		}else {
    			l = mid + 1;
    		}
    	}
    	return nums[l] == target;
    }
};