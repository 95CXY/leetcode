// Author: yiouejv
// Email: yiouejv@126.com
// -------------------------------------- 暴力超时
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int i = 0;
        int j = 0;
        int ans = 0;

        while (i < A.size()) {

            int k = 0;  // 在B中找到A[i]的位置
            int Bi = 0;
            while (Bi < B.size()) {
                k = Bi;
                while (k < B.size() && B[k] != A[i]) {
                    k++; Bi = k;
                }
                while (j < A.size() && k < B.size() && B[k] == A[j]) {
                    k++; j++;
                }
                ans = max(ans, j - i);
                Bi ++;
                j = i;
                if (ans == A.size()) return ans;
            }

            i++; j = i;
        }
        return ans;
    }
};