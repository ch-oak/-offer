// 10：③变态跳台阶.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include "pch.h"
#include <iostream>


class Solution {
public:
	/*
	一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
	*/
	//f(n) = f(n-1) + f(n-2) + ... + f(0) = 2*f(n-1)
	int jumpFloorII(int number) {
		return pow(2, number - 1);//这里并不是求等比数列的和，直接求通项
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
