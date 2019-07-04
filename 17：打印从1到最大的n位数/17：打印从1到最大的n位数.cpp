// 17：打印从1到最大的n位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//无OJ

#include "pch.h"
#include <iostream>

using namespace std;
/*
输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数即999.
*/
class Solution {
public:
	void print1ToMaxN(int n) {
		if (n <= 0)
			return;
		char *num = new char[n + 1];
		num[n] = '\0';
		print1ToMaxNHelp(n,0,num);

		delete[] num;

	}

private:
	void print1ToMaxNHelp(int len,int index,char* num) {
		if (index == len) {
			printNum(num, len);
			return;
		}
		for (int i = 0; i < 10; i++) {//递归的在每一位从0变到9
			num[index] = '0' + i;
			print1ToMaxNHelp(len, index + 1, num);
		}
	}
	void printNum(char* num, int len) {
		int i;
		for (i = 0; i < len; i++) {
			if (num[i] != '0')
				break;
		}
		char *temp = &num[i];
		if (i == len)//第一个0
			cout << "0" << endl;
		else {
			for (; i < len; i++)
				cout << num[i];
			cout << endl;
		}
	}
};

int main()
{
	Solution().print1ToMaxN(2);
    std::cout << "Hello World!\n"; 
}


