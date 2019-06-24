// 56：数组中只出现一次的两个数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
	*/
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {

		int temp = data[0];
		for (int i = 1; i < data.size(); i++)
			temp ^= data[i];//因为有两个数字不同，所以异或结果一定不为0
		int pos = temp - (temp & (temp - 1));//10000,1所在的位置为从右往左数第一个1
		int res1, res2;
		bool flag1 = true, flag2 = true;//可以不使用flag直接令初始res为0，因为0异或任何数都得该数本身
		for (int i = 0; i < data.size(); i++) {
			if ((data[i] & pos) != 0) {
				if (flag1) {
					res1 = data[i];
					flag1 = false;
				}
				else
					res1 ^= data[i];
			}
			else {
				if (flag2) {
					res2 = data[i];
					flag2 = false;
				}
				else
					res2 ^= data[i];
			}
		}
		*num1 = res1;
		*num2 = res2;
	}
};


int main()
{
	int num1, num2;
	vector<int> data{ 2,4,3,6,3,2,5,5 };
	Solution().FindNumsAppearOnce(data, &num1, &num2);
    std::cout << "Hello World!\n"; 
}
