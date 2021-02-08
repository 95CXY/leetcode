// Author: yiouejv
// Email: yiouejv@126.com
// ------------------------------------ 方法2，二分查找

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];

        int rIndex = 0;
        int cIndex = 0;

        while (l <= r) {
            // 取第一个元素和最后一个元素的mid
            int mid = l + (r - l) / 2;
            rIndex = n - 1; cIndex = 0;

            // 统计小于等于mid的元素个数
            int countLeft = 0;
            while (rIndex >= 0 && rIndex < n && cIndex >= 0 && cIndex < n) {
                if (matrix[rIndex][cIndex] <= mid) {
                    if (cIndex < n - 1) {
                        cIndex ++;
                    } else {
                        countLeft += cIndex;
                        if (matrix[rIndex][cIndex] <= mid) countLeft++;
                        rIndex --;
                    }
                }else {
                    rIndex --;
                    countLeft += cIndex;
                }
            }
            // 二分
            if (k > countLeft) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};