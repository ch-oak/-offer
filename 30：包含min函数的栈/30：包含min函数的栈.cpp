// 30：包含min函数的栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

//设置一个辅助栈保存最小值，如压入元素小于栈顶元素直接压入，否则压入栈顶元素
//辅助栈的大小与数据栈的大小一致，栈顶永远是当前数据住哪

class Solution {
public:
	void push(int value) {
		dataStack.push(value);
		if (minStack.size() == 0 || value < minStack.top())//最初辅助栈为空
			minStack.push(value);
		else
			minStack.push(minStack.top());//辅助栈的大小与数据栈的大小一致，栈顶永远是当前数据住哪
	}
	void pop() {
		dataStack.pop();
		minStack.pop();
	}
	int top() {
		return dataStack.top();
	}
	int min() {
		return minStack.top();
	}
private:
	stack<int> minStack;
	stack<int> dataStack;
};

int main()
{
	Solution s;
	s.push(1);
	s.push(2);
	s.push(1);
	cout << s.min();
	std::cout << "Hello World!\n";
}

