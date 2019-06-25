// 10：②青蛙跳台阶问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>

class Solution {
public:
	/*
	一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
	*/
	int jumpFloor(int number) {//第n阶台阶可以是跳一个台阶上来的，也可以是跳两个台阶上来的。
		int res[] = { 0,1,2 };
		if (number <= 2)
			return res[number];
		int F_1 = 2, F_2 = 1;
		int F;
		for (int i = 3; i <= number; i++) {
			F = F_1 + F_2;
			F_2 = F_1;
			F_1 = F;
		}
		return F;
	}
};
int main()
{
    std::cout << "Hello World!\n"; 
}
