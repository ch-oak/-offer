// 67：把字符串转换成整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	/*
	将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
	要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
	*/
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int res = 0;
		int sig = 1;
		int len = str.size();
		int start = 0;
		if (str[0] == '-')
			sig = -1, start = 1;
		else if (str[0] == '+')
			sig = 1, start = 1;
		if (start == 1 && str.size() == 1)
			return 0;
		for (int i=start; i<len; i--) {
			if (str[i] > '0'&&str[i] < '9')
				res = res*10 + (str[i] - '0');
			else
				return 0;
		}
		return sig * res;
	
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
