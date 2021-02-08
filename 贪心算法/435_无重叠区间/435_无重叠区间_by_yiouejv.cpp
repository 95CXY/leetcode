
/*
	贪心: 区间结尾越小，留给其他区间的空间越大，所以，我们把原区间列表按照结尾的大小进行升序排序。
	再判断区间是否重叠
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> vec1, vector<int> vec2){
            return vec1[1] < vec2[1];
        });

        int ans = 0, pre = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (pre > intervals[i][0]) {
                ans ++;
            } else {
                pre = intervals[i][1];
            }
        }
        return ans;
    }
};
