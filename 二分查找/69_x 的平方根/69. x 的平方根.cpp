// Author: yiouejv
// Email: yiouejv@126.com

class Solution {
public:
    int mySqrt(int x) {
    	if (x == 0 || x == 1) return x;
        int l = 0;
        int r = x;

        while (l < r) {
        	if (r - l == 1) return l;
        	long int mid = l + (r - l ) / 2;
        	if (mid * mid > x) {
        		r = mid;
        	} else if ( mid * mid < x) {
        		l = mid;
        	} else {
        		return mid;
        	}
        }
        return l;
    }
};