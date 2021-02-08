/*
	Author: yiouejv
*/
// 解题思路: 同向双指针，用value来保存当前可重复的值， countValue 记录value当前出现了几次
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int size = nums.size();
        if (size==0) return 0;
        int i = 0;
        int j = 0;
        int value = nums[0];
        int countValue = 0;
        while (j < size)
        {
            if (i == 0)
            {
                nums[i++] = nums[j++];
                countValue ++;
                continue;
            }
            if (countValue < 2)
            {
                if (nums[j] == value)
                {
                    countValue ++;
                }
                else
                {
                    countValue = 1;
                    value = nums[j];
                }
                nums[i++] = nums[j++];
            }
            else
            {
                if (nums[j] != nums[i-1])
                {
                    nums[i] = nums[j];
                    value = nums[i];
                    countValue = 1;
                    i++; j++;
                }
                else
                {
                    j++;
                }
            }
            
        }
        return i;
    }
};