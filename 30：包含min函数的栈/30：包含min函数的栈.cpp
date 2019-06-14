// 30：包含min函数的栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;


//设置一个辅助栈保存最小值，如压入元素小于栈顶元素直接压入，否则压入栈顶元素

class Solution {
public:
	void push(int value) {
		dataStack.push(value);
		if (minStack.size() == 0 || value < minStack.top())//最初辅助栈为空
			minStack.push(value);
		else
			minStack.push(minStack.top());
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

