class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](vector<int> a , vector<int> b) {
            return a[1] < b[1];
        });

        int ans = 1, i = 1, n = points[0][1], len = points.size();
        while (i < len) {
            if (n >= points[i][0]) {
                i++;
            } else {
                n = points[i][1];
                ans ++;
            }
        }
        return ans;
    }
};