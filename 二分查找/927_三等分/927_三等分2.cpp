// Author: yiouejv
// Email: yiouejv@126.com
// -------------------  [0,1,0,1,1,0,1,1,0,1]
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

        // 1/3处的1最左端的下标
        int One_ThreeIndex = getIndex(A, 1, sumOne / 3);
        // 2/3处的1最左端的下标
        int Two_ThreeIndex = getIndex(A, 1, 2*sumOne / 3);

        // 统计后缀0的个数
        int countSuffixZero = 0;
        int Three_ThreeIndex = A.size() - 1;
        while (Three_ThreeIndex >= 0 && A[Three_ThreeIndex] != 1) {
            countSuffixZero ++;
            Three_ThreeIndex--;
        }

        // // 判断第一部分的后缀0够不够
        // int i = One_ThreeIndex; int countZero = 0;
        // while (i < Two_ThreeIndex && A[i] == 0) {
        //     countZero++; i++;
        // }
        // if (countZero < countSuffixZero) {
        //     ans.assign(2, -1); return ans;
        // }

        // // 判断第二部分的后缀0够不够
        // i = Two_ThreeIndex; countZero = 0;
        // while (i < Three_ThreeIndex && A[i] == 0) {
        //     countZero ++; i++;
        // }
        // if (countZero < countSuffixZero) {
        //     ans.assign(2, -1); return ans;
        // }

        // 判断后缀0前面的数位是否相同
        int end1 = Two_ThreeIndex - countSuffixZero;
        int end2 = Three_ThreeIndex - 1;
        int end3 = A.size() - 1;
        int pos1 = end1;
        int pos2 = end2;
        while (pos1 >= 0 && pos2 > end1 && end3 > end2) {
            if (A[pos1] == A[pos2] && A[pos1] == A[end3]) {
                pos1 --; pos2 --; end3 --;
            } else {
                ans.assign(2, -1); return ans;
            }
        }

        ans.push_back(One_ThreeIndex);
        ans.push_back(Two_ThreeIndex+1);
        return ans;
    }

    int getIndex(vector<int> A, int target, int count) {
        int i = 0;
        for (; i<A.size(); i++) {
            if (A[i] == target) {
                count --;
            }
            if (count == -1) {
                return i;
            }   
        }
        return i;
    }
};