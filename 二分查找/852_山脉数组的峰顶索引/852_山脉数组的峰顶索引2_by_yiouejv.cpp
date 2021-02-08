// Author: yiouejv
// Email: yiouejv@126.com

/*

由题意得我们需要找到一个下标，其对应的元素大于其他所有的元素。

arr[mid] > arr[mid+1] 则最大值有可能在 [left, mid] 之间，注意mid也可能是最大值，

否则的话最大值就在[mid+1, right] 之间，mid 不会是最大值

*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};