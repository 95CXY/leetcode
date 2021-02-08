class Solution {
public:
    int mySqrt(int x) {
    	if (x == 0 || x == 1) return x;
    	int l = 0, r = x, mid, sqrt;
    	while (l < r - 1) {
    		mid = l + (r - l) / 2;
    		sqrt = x / mid;
    		if (sqrt > mid) {
    			l = mid;
    		}else if (sqrt < mid) {
    			r = mid;
    		}else {
    			return mid;
    		}
    	}
    	return l;
    }
};