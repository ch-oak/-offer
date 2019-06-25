// 09：用两个栈实现队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty()) {//当第二个栈为空时，先将第一个栈的所有元素都放到第二个栈中去
			while (!stack1.empty()) {
				int temp = stack1.top();
				stack1.pop();
				stack2.push(temp);
			}
		}
		//当第二个栈不为空时，直接弹出元素
		int temp = stack2.top();
		stack2.pop();
		return temp;
		
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
    std::cout << "Hello World!\n"; 
}