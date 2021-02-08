//////////////////////////////////////////////   方法一
/*
	[0,1,0,2,1,0,1,3,2,1,2,1]
	i位置能接的雨水等于 [0, i]中的最大值 maxLeft, 和 [i, n-1] 的最大值maxRight 取两者的最小值 - i位置的高度，即为min(maxLeft, maxRight) - height[i]
	时间复杂度 O(n^2)
	空间复杂度 O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
    	const int size = height.size();
        int ans = 0;

        for (int i=0; i < size; i++)
        {
        	int maxLeft = getMaxValue(height, 0, i);
    		int maxRight = getMaxValue(height, i, size-1);
    		ans += (min(maxLeft, maxRight) - height[i]);
        }
        return ans;
    }

    int getMaxValue(vector<int> height, int startIndex, int endIndex)
    {
    	int maxValue = height[startIndex];
    	for (int i = startIndex; i <= endIndex; ++i)
    	{
    		maxValue = max(maxValue, height[i]);
    	}
    	return maxValue;
    }
};


//////////////////////////////////////////   方法二
/*
	我们可以遍历数组，找出从左往右看的最大值和从右往左看的最大值，缓存在两个数组中
	再遍历数组，根据 min(maxLeft, maxRight) - height[i] 累加即可得到雨水的面积
	时间复杂度O(n)
	空间复杂度O(n)
*/

class Solution {
public:
	int trap(vector<int> &height) {
		const int size = height.size();
		vector<int> leftMax(size);
		vector<int> rightMax(size);

		// 从左往右看，找出每个位置的左最大值
		for (int i = 0; i < size; ++i)
		{
			if (i == 0) leftMax[0] = height[0];
			else
			{
				leftMax[i] = max(leftMax[i-1], height[i]);
			}
		}

		// 从右往左看，找出每个位置的右最大值
		for (int j = size-1; j >= 0; j--)
		{
			if (j == size - 1) rightMax[j] = height[size-1];
			else
			{
				rightMax[j] = max(rightMax[j+1], height[j]);
			}
		}

		// 遍历height, 求出结果
		int ans = 0;
		for (int i = 0; i < size; i++)
		{
			ans += min(leftMax[i], rightMax[i]) - height[i];
		}
		return ans;
	}
};


///////////////////////////////////////////////////////// 方法三
/*
	双指针
	

*/
