// 15：二进制中1的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&tPage=1&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

//1不断左移和目标相与
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		unsigned int flag = 1;
		while (flag) {
			if (flag&n)
				count++;
			flag <<= 1;
		}
		return count;
	}
};

//与减去1的自己相与相当于把最右边的1变为0
//记录多少次可以将目标变为0
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n) {
			n &= n - 1;//与减去1的自己相与相当于把最右边的1变为0
			count++;
		}
		return count;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

