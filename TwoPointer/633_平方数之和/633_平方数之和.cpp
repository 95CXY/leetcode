class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0, j = long(sqrt(c));
        while (i <= j) {
            long s = c - j*j;
            if (i*i > s) {
                --j;
            }else if (i*i < s) {
                ++i;
            }else {
                return true;
            }
        }
        return false;
    }
};

