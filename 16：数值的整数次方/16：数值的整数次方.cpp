// 16：数值的整数次方.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&tPage=1&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking


#include "pch.h"
#include <iostream>

using namespace std;

/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
*/

//注意考虑指数为负数的情况
class Solution {
public:
	double Power(double base, int exponent) {
		if (base == 0)
			return 0;
		if (base == 1||exponent==0)
			return 1;
		double res = 1.0;
		if (exponent < 0) {
			unsigned int u_exponent = (unsigned int)(-exponent);
			res = 1/PowerHelp(base, u_exponent);
		}
		else {
			unsigned int u_exponent = (unsigned int)(exponent);
			res = PowerHelp(base, u_exponent);
		}
		return res;
	}
private:
	double PowerHelp(double base, unsigned int exponent) {

		if (exponent == 0)
			return 1;
		if (exponent == 1)
			return base;
		double res = 1.0;

		res *= PowerHelp(base, exponent >> 1);
		res *= res;
		if (exponent & 1 == 1)
			res *= base;
		return res;
	}

	double PowerHelp1(double base, unsigned int exponent) {
		double res = 1.0;
		//循环解法
		while (exponent != 0) {
			if ((exponent & 1) == 1)
				res *= base;//每次遇到奇数要乘以当前的base
			base *= base;// 翻倍
			exponent >>= 1;// 右移一位
		}
		return res;
	}
};

int main()
{

	cout << Solution().Power(2, -7);
    std::cout << "Hello World!\n"; 
}


