/*
	Author: yiouejv
	解题思路: 如果全是非负数，则直接平方返回； 如果全是负数，返回平方的逆序;
			如果有正有负，则找到负数的下标negative, [0, negative]是负数，[negative+1, A.size() - 1] 是非负数，
			先用一个temp数组保存原数组的平方结果, 接着把两个区间看成两个数组，依次从数组中找出较小的值push_back到ans中(类似于合并两个有序数组)
*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        vector<int> temp;
        int negative = -10;  // 最后一个复数的位置，正常情况不可能到-10
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] >= 0)
            {
                negative = i - 1; break;
            }
        }

        for (int i = 0; i < A.size(); ++i)
        {
            temp.push_back(A[i] * A[i]);
        }
        if (negative < 0) return temp;
        else if (negative == -10)  // 说明没找到>=0的数，则全是负数
        {
            reverse(temp.begin(), temp.end());
            return temp;
        }
        else
        {
            int i = negative;
            int j = negative + 1;
            while (i >= 0 && j < A.size())
            {
                if (temp[i] < temp[j])
                    ans.push_back(temp[i--]);
                else
                    ans.push_back(temp[j++]);
            }
            while (i >= 0)
            {
                ans.push_back(temp[i--]);
            }
            while (j < A.size())
            {
                ans.push_back(temp[j++]);
            }
        }
        return ans;
    }
};