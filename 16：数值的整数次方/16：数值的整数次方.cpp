// 16：数值的整数次方.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

/*给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方*/

#include "pch.h"
#include <iostream>

using namespace std;
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
		if (base == 1)
			return 1;
		if (exponent == 0)
			return 1;
		double res = 1.0;
		res *= PowerHelp(base, exponent >> 1);
		res *= res;
		if (exponent & 1 == 1)
			res *= base;
		return res;
	}
};

int main()
{

	cout << Solution().Power(2, -3);
    std::cout << "Hello World!\n"; 
}


