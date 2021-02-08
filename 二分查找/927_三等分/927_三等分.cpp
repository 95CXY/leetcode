// Author: yiouejv
// Email: yiouejv@126.com

/*
	1 0 1 0 1
	[0, i]
	(i, j)
	[j, length - 1]
*/
// -------------------  双指针，超时

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
    	vector<int> ans;
    	vector<int> section1;
    	vector<int> section2;
    	vector<int> section3;

    	int sumOne = 0;
        for (int i: A) sumOne += i;
        if (sumOne % 3 != 0) {
            ans.assign(2, -1);
            return ans;
        }

    	int i = 0;
    	int j = i + 2;

    	while (i < A.size()) {
    		while (j < A.size()) {
    			section1.assign(A.begin(), A.begin()+i+1);
    			section2.assign(A.begin()+i+1, A.begin()+j);
    			section3.assign(A.begin()+j, A.end());

    			int p1 = section1.size() - 1;
    			int p2 = section2.size() - 1;
    			int p3 = section3.size() - 1;

    			while (
    				   (p1 < 0 && p2 >= 0 && p3 >= 0 && section2[p2] == section3[p3] && section3[p3] == 0)
				    || (p1 < 0 && p2 < 0 && section3[p3] == 0)
				    || (p1 < 0 && p3 < 0 && section2[p2] == 0)

    				|| (p2 < 0 && p1 >= 0 && p3 >= 0 && section1[p1] == section3[p3] && section3[p3] == 0)
					|| (p2 < 0 && p1 < 0 && section3[p3] == 0)
				    || (p2 < 0 && p3 < 0 && section1[p1] == 0)    				

    				|| (p3 < 0 && p1 >= 0 && p2 >= 0 && section1[p1] == section2[p2] && section1[p1] == 0)
    				|| (p3 < 0 && p1 < 0 && section2[p2] == 0)
				    || (p3 < 0 && p2 < 0 && section1[p1] == 0)

					|| (p1 >= 0 && p2 >= 0 && p3 >= 0 && section1[p1] == section2[p2] && section2[p2] == section3[p3])
    			) {
    				p1--; p2--; p3--;
    				if (p1 < 0 && p2 < 0 && p3 < 0) {
    					ans.push_back(i);
    					ans.push_back(j);
    					return ans;
    				}
    			}
    			j++;
    		}
    		i++; j = i+2;
    	}
    	ans.push_back(-1);
    	ans.push_back(-1);
    	return ans;
    }
};