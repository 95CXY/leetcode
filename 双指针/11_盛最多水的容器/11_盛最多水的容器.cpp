/*
    双指针法，首尾两个指针保证了宽度由大到小，首尾两个指针向中间靠拢。
    靠拢规则：指向较小数的指针往中间靠拢，直到尾指针小于等于首指针。保存之间最大的面积
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxarea = 0;
        while (j > i)
        {
            int r = (j - i) * min(height[i], height[j]);
            maxarea = max(maxarea, r);
            if (height[i] < height[j])
                i++;
            else
                j --;
        }
        return maxarea;
    }
};