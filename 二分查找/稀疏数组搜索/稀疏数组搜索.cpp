// Author: yiouejv
// Email: yiouejv@126.com

class Solution {
public:
    int findString(vector<string>& words, string s) {
    	int l = 0;
    	int r = words.size() - 1;

    	while (l <= r) {
    		while (words[l] == "") l++;
    		while (words[r] == "") r--;

    		int mid = l + (r - l) / 2;
    		while (mid <= r && words[mid] == "") {
    			mid ++;
    		}
    		if (words[mid] > s) {
    			r = mid - 1;
    		} else if (words[mid] < s) {
    			l = mid + 1;
    		} else {
    			return mid;
    		}
    	}
    	return -1;
    }
};