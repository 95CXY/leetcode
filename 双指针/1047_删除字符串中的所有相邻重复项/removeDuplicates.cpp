
// 解法一: 双指针
/*
	a  b  b  a  c  a

    i  j

       i  j

   a a c a
   i j

   说明: i, j=i+1 两个指针遍历字符串，i，j指向的字符相等则删除，接着从头开始遍历，直至j到字符串的尾部
   时间复杂度O(n);
   空间复杂度(1);
*/

class Solution {
public:
    string removeDuplicates(string S) {
    	if (S.size() <= 1) return S;

    	int i = 0;
    	int j = 1;
    	while (i < j && j < S.size())
    	{
    		if (S[i] == S[j])
    		{
				S.erase(i, 2);
				i = 0; j = 1;
				continue;
    		}
	    	i ++;
	    	j ++;
    	}
    	return S;
    }
};


// 解法二: 模拟入栈操作1
/*
	依次遍历字符串入栈，将要入栈的元素和栈顶元素相同则取消该入栈操作，接着弹出栈顶元素，直至遍历结束
	|  |
	 ——
	|b |
	 ——
	|b |
	 ——
	|a |
	 ——
	 接着用另一个栈接收之前的栈元素，构建字符串
	时间复杂度O(n);
	空间复杂度(n);
*/

class Solution {
public:
    string removeDuplicates(string S) {
    	if (S.size() <= 1) return S;

    	stack<char> stack1;
    	for (int i = 0; i < S.size(); ++i)
    	{
    		if (!stack1.empty() && stack1.top() == S[i])
    			stack1.pop();
    		else
    			stack1.push(S[i]);
    	}

    	stack<char> stack2;
    	while (!stack1.empty())
    	{
    		char c = stack1.top();
    		stack2.push(c);
    		stack1.pop();
    	}

    	string ret;
    	while (!stack2.empty())
    	{
    		char c = stack2.top();
    		stack2.pop();
    		ret.append(1, c);
    	}
    	return ret;
    }
};



// 解法二: 模拟入栈操作2
/*
	依次遍历字符串入栈，将要入栈的元素和栈顶元素相同则取消该入栈操作，接着弹出栈顶元素，直至遍历结束
	|  |
	 ——
	|b |
	 ——
	|b |
	 ——
	|a |
	 ——
	在原字符串的基础上进行删除操作。
	时间复杂度O(n);
	空间复杂度(1);
*/
class Solution {
public:
    string removeDuplicates(string S) {
    	if (S.size() <= 1) return S;

    	stack<char> stack1;
    	int i = 0;
    	while (i < S.size())
    	{
    		if (!stack1.empty() && stack1.top() == S[i])
    		{
    			stack1.pop();
    			S.erase(i-1, 2);
    			i --;
    		}
    		else
    		{
    			stack1.push(S[i++]);
    		}
    	}
    	return S;
    }
};
