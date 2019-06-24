// 58：②左旋字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	/*
	汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
	对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
	要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
	*/

	string LeftRotateString(string str, int n) {
		if (str.empty())
			return {};
		n %= str.size();
		if (n == 0)
			return str;
		ReverseCore(str, 0, n - 1);
		ReverseCore(str, n, str.size() - 1);
		ReverseCore(str, 0, str.size() - 1);
		return str;
	}
private:
	void ReverseCore(string &str, int pos1, int pos2) {
		while (pos1 < pos2) {
			swap(str[pos1++], str[pos2--]);
		}
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
