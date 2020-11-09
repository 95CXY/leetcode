// Author: yiouejv
// Email: yiouejv@126.com
// ------------------------------------ 方法1，碾平数组，排序

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> vecFloor;
        for (auto vec: matrix) {
            for (int v: vec) {
                vecFloor.push_back(v);
            }
        }
        sort(vecFloor.begin(), vecFloor.end());
        return vecFloor[k-1];
    }
};