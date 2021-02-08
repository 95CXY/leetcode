// Author: yiouejv
// Email: yiouejv@126.com
// -----------------------------   方法1，时间复杂度O(n^2)
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        if (a.empty() && isPalindrome(b)) return true;
        for (int i = 0; i < a.size(); i++) {
            string aPrefix(a, 0, i);
            string bSuffix(b.begin()+i, b.end());
            if (isPalindrome(aPrefix + bSuffix)) {
                return true;
            }
            string bPrefix(b, 0, i);
            string aSuffix(a.begin()+i, a.end());
            if (isPalindrome(bPrefix + aSuffix)) {
                return true;
            }
        }
        return false;
    }

    bool isPalindrome(string target) {
        if (target.size() == 0) return true;
        int i = 0;
        int j = target.size() - 1;

        while (i < j) {
            if (target[i] != target[j]) {
                return false;
            }
            i++; j--;
        }
        return true;
    }
};