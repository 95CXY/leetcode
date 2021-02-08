// Author: yiouejv
// Email: yiouejv@126.com
// -------------------------------------- 滑动窗口
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int startIndex = 0;
        int ans = 0;
  
        while (startIndex < A.size() && startIndex < B.size()) {
            
            int len1 = maxLength(startIndex, A, B);
            int len2 = maxLength(startIndex, B, A);
            ans = max(ans, max(len1, len2));
            startIndex ++;

        }

        return ans;
    }

    int maxLength(int startIndex, vector<int> A, vector<int> B){
        int i = startIndex; int j = 0;
        int count = 0;  // 统计相等的元素的个数
        int ans = 0;

        while (i < A.size() && i < B.size()) {

            if (B[i] == A[j])
            {
                count ++;
            } else {
                ans = max(ans, count);
                count = 0;
            }

            i++; j++;
        }

        ans = max(ans, count);
        return ans;
    }
};