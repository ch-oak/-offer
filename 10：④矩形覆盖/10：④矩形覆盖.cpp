// 10：④矩形覆盖.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>


class Solution {
public:
	/*
	我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
	*/
	int rectCover(int number) {//f(n) = f(n-1) + f(n-2)
		int res[] = { 0,1,2 };
		if (number <= 2)
			return res[number];
		int f_1 = 2, f_2 = 1;
		int f_n;
		for (int i = 3; i <= number; i++) {
			f_n = f_1 + f_2;
			f_2 = f_1;
			f_1 = f_n;
		}
		return f_n;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
