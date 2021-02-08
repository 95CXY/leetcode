// Author: yiouejv
// Email: yiouejv@126.com

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<vector<int>> ans;

    	int i = 0;
    	int size = nums.size();
    	while (i < size - 1) {
    		if (i == 0 || nums[i] != nums[i - 1]) {
	    		auto result = twoSum(nums, -nums[i], i+1, size-1);
	    		for (auto v: result) {
	    			ans.push_back(v);
	    		}
    		}
    		i ++;
    	}
    	return ans;
    }

    vector<vector<int>> twoSum(vector<int> &nums, int target, int startIndex, int stopIndex) {
    	int i = startIndex;
    	int j = stopIndex;
    	vector<vector<int>> ret;

    	while (i < j) {
    		int _sum = nums[i] + nums[j];
    		if (_sum < target) {
    			i++;
    		} else if (_sum > target) {
    			j--;
    		} else {
    			vector<int> temp;
    			temp.push_back(-target);
    			temp.push_back(nums[i]);
    			temp.push_back(nums[j]);
    			if (!hasElement(ret, temp)) {
    				ret.push_back(temp);
    			}
    			i++; j--;
    		}
    	}
    	return ret;
    }

    bool hasElement(vector<vector<int>> vecs, vector<int> vec) {
    	for (auto v: vecs) {
    		if (v == vec) {
    			return true;
    		}
    	}
    	return false;
    }
};