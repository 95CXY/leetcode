class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	if (nums1.empty() && nums2.empty()) return new double(0);
    	if (nums1.empty() && !nums2.empty()) {
    		if (nums2.size() & 1) return new double(nums2[ nums2.size() / 2 ]);
    		else {
    			int mid = nums2.size() / 2;
    			return (new double(nums2[mid-1]) + new double(nums2[mid])) / 2;
    		}
    	}
    	if (!nums1.empty() && nums2.empty()) {
    		if (nums1.size() & 1) return new double(nums1[ nums1.size() / 2 ]);
    		else {
    			int mid = nums1.size() / 2;
    			return (new double(nums1[mid-1]) + new double(nums1[mid])) / 2;
    		}
    	}

    	int length1 = nums1.size(), length2 = nums2.size();
    	if ((length1 + length2) & 1) {
    		return new double(min(nums1[length1 / 2], nums2[length2 / 2]));
    	}else {
    		int mid1 = length1 / 2;
    		int mid2 = length2 / 2;
    		int n1 = new double(nums1[mid1-1]);
    		int n2 = new double(nums1[mid1]);
    		int n3 = new double(nums2[mid2-1]);
    		int n4 = new double(nums2[mid2]);
    		vector<int> vec{n1, n2, n3, n4};
    		sort(vec.begin(). vec.end());
    		return (new double(vec[mid-1]) + new double(vec[mid])) / 2;
    	}
    }
};