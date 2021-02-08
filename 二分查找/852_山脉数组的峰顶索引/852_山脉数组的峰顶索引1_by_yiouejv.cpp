// Author: yiouejv
// Email: yiouejv@126.com

/*

由题意得我们需要找到一个下标，其对应的元素大于其他所有的元素。

我们使用二分查找，二分取一个mid，判断arr[mid] 是否全都大于mid 左侧的元素，如果存在比nums[arr]大的元素，则最大的元素在[left: mid - 1] 之间，不包括mid

否则再判断 [mid+1: right] 区间所有的元素，如果全都比arr[mid] 小，则mid就是我们要找的下标，如果存在比arr[mid]大的元素，则最大值在[mid+1, right]之间，不包括mid

*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (allLess(arr, left,  mid-1, arr[mid])) {
                if (allLess(arr, mid + 1, right, arr[mid])) {
                    return mid;
                }else {
                    left = mid + 1;
                }
            }else {
                right = mid - 1;
            }
        }
        return left;
    }

    bool allLess(vector<int> arr, int start, int stop, int m) {
        for (int i = start; i <= stop; i++) {
            if (arr[i] >= m) return false;
        }
        return true;
    }
};