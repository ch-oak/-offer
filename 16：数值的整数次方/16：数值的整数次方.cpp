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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
