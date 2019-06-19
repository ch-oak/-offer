// 39：数组中出现次数超过一半的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		int res = numbers[0];
		int times = 1;

		//出现次数超过一半的数字一定比其他所有数字的次数都多
		for (int i = 1; i < numbers.size(); i++) {
			if (numbers[i] == res)
				times++;
			else {
				if (times == 0) {
					res = numbers[i];
					times = 1;
				}
				else
					times--;
			}
		}
		times = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] == res)
				times++;
		}
		if (times * 2 <= numbers.size())
			return 0;
		else
			return res;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

