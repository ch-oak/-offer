// 31：栈的压入、弹出序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() && popV.empty())
			return true;
		stack<int> data;
		int len = popV.size();
		int i = 0;
		int j = 0;
		while(j<len) {//循环结束的条件为出栈序列走到尽头
			//往栈里压元素，直到栈顶元素与出栈序列相等
			while (data.empty() || data.top() != popV[j]) {
				if (i == len)
					break;
				data.push(pushV[i++]);
			}
			if (data.top() != popV[j])
				break;
			data.pop();
			j++;
		}
		if (data.empty() && j == len)
			return true;
		return false;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

