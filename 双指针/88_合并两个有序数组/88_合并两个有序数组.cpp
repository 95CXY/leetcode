/*
	这里我们使用了 ++ 和--的小技巧：a++ 和 ++a 都是将 a 加 1，但是 a++ 返回值为 a，
	而 ++a 返回值为 a+1。如果只是希望增加 a 的值，而不需要返回值，则推荐使用 ++a，其运行速度 会略快一些。 
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, pos = nums1.size() - 1;
		
		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				nums1[pos--] = nums1[i--];
			}else {
				nums1[pos--] = nums2[j--];
			}
		}
		while (i >= 0) {
			nums1[pos--] = nums1[i--];
		}
		while (j >= 0) {
			nums1[pos--] = nums2[j--];
		}
    }
};