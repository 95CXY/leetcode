/*
    Author: yiouejv
    Email: yiouejv@126.com
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (j < typed.size()) {
            if (name[i] == typed[j]) {
                i++; j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.size();
    }
};