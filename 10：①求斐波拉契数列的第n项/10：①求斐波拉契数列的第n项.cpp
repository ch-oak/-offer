// 10：①求斐波拉契数列的第n项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>

class Solution {
public:
	/*
	大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
	n<=39
	*/
	int Fibonacci(int n) {
		int res[2] = { 0,1 };
		if (n < 2)
			return res[n];
		int F_1 = 1, F_2 = 0;
		int F_n;
		for (int i = 2; i <= n; i++) {//用两个变量存储前面的值
			F_n = F_1 + F_2;
			F_2 = F_1;
			F_1 = F_n;
		}
		return F_n;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
