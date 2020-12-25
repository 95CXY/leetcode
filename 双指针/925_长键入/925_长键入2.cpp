class Solution {
public:
    bool isLongPressedName(string name, string typed) {
    	int i = 0, j = 0;
    	while (i < name.size() && j < typed.size()) {
    		if (name[i] == typed[j]) {
    			++j;
				if (i+1 < name.size() && name[i+1] == typed[j]) ++i;
    		}
    		else return false;
    	}
    	if (i < name.size() - 1) return false;
    	if (j < typed.size() - 1) return false;
    	return i == name.size() - 1;
    }
};