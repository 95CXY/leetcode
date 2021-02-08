// Author: yiouejv
// Email: yiouejv@126.com
// -------------------
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> ans;
        // 判断1能不能被等分3份
        int sumOne = 0;
        for (int i: A) sumOne += i;
        if (sumOne % 3 != 0) {
            ans.assign(2, -1);
            return ans;
        }
        if (sumOne == 0) {
            ans.push_back(0);
            ans.push_back(A.size() - 1);
            return ans;
        }

        // 统计后缀0的个数
        int countSuffixZero = 0;
        int last_1 = A.size() - 1;
        while (A[last_1] != 1) {
            last_1 --;
            countSuffixZero++;
        }

        // 找到第1/3个1的位置
        int oneThree = getIndex(A, 1, sumOne / 3);
        // 找到第2/3个1的位置
        int twoThree = getIndex(A, 1, (sumOne * 2) / 3);
        int end1 = oneThree + countSuffixZero;
        int end2 = twoThree + countSuffixZero;
        int end3 = A.size() - 1;
        int pos1 = end1; int pos2 = end2;

        while (end1 >= 0 && end2 > pos1 && end3 > pos2) {
            if (A[end1] == A[end2] && A[end1] == A[end3]) {
                end1 --; end2 --; end3 --;
            } else {
                ans.assign(2, -1);
                return ans;
            }
        }
        
        ans.push_back(pos1);
        ans.push_back(pos2+1);
        return ans;
    }

    int getIndex(vector<int> A, int target, int count) {
        int i = 0;
        for (; i<A.size(); i++) {
            if (A[i] == target) {
                count --;
            }
            if (count == 0) {
                return i;
            }   
        }
        return i;
    }
};