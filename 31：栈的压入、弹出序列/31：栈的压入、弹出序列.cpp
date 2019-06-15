// 31：栈的压入、弹出序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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

