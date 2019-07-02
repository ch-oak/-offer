// 65：不用加减乘除做加法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>


/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号
*/
class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum, carry;
		int temp,res;
		while(true){
			sum = num1 ^ num2;//两个数相异或，相当于直接求和，不计算进位
			carry = (num1&num2) << 1;//两数相与在左移，相当于求出进位值
			if (carry==0) {//不断加上进位值，总会停止的
				res = sum;
				break;
			}
			else {
				num1 = sum;
				num2 = carry;
			}
		}
		return res;
	}
};
int main()
{
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
