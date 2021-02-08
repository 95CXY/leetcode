// Author: yiouejv
// Email: yiouejv@126.com
// -----------------------------   方法2 时间复杂度O(n)
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }

    bool check(string &a, string &b) {
        int i = 0;
        int j = a.size() - 1;
        while (a[i] == b[j]) {
            i++; j--;
        }
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

    bool isPalindrome(string &s, int i, int j) {
        while (s[i] == s[j]) {
            i++; j--;
        }
        return i >= j;
    }
};