/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;

        // all in [0, p0)  == 0
        // all in [p0, p2)  == 1
        // all in (p2, size -1] == 2
        int p0 = 0;
        int p2 = nums.size() - 1;
        int i = 0;
        while (i <= p2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0++]);
                i++;
            }else if (nums[i] == 1) {
                i++;
            }else {
                swap(nums[i], nums[p2--]);  // i 不自加，因为还不知道i位置交换回来是什么元素
            }
        }
    }
};
// @lc code=end

