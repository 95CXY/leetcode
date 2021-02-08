/*
	双指针，需要保持相对顺序，用两个向后的指针

	j 用来遍历数组，一直往后走，
	i 用来指向即将被交换的元素的下标，也就是0的下标
	交换条件，nums[j] != 0  nums[i] == 0

	[0, 1, 0, 3, 12]
		0   1   0   3   12
		ij

		1   0   0   3   12
		    i       j


		1   3   0   0   12
		        i       j

		1   3   12   0  0
		        i       j

    [1, 0, 2, 3, 12]
    	1   0   2   3   12
		ij

		1   0   2   3   12
		    ij
		    i   j

		1   2   0   3   12
		        i   j

		1   2   3   0   12
		            i    j

		1   2   3   12  0

	[0, 0]
		0   0
		ij 
		    j
*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	if (nums.size()  <= 1) return;
    	int i = 0;
    	int j = 0;
    	while (j < nums.size())
    	{
    		if (nums[i]==0 && nums[j]!=0)
    			Solution::swap(nums, i, j);
    		if (nums[i] != 0) i++;
    		j++;
    	}
    	
    }

    static void swap(vector<int> &nums, int i, int j)
    {
    	int t = nums[i];
    	nums[i] = nums[j];
    	nums[j] = t;
    }
};

