// 57：①和为s的连续正数序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	/*
	输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
	*/
	//先排序，首尾指针移动
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		sort(array.begin(), array.end());
		int start = 0;
		int end = array.size() - 1;
		vector<int> res;
		while (start <= end) {
			int temp = array[start] + array[end];
			if (temp < sum)
				++start;
			else if (temp > sum)
				--end;
			else {
				res.push_back(array[start]);
				res.push_back(array[end]);
				break;
			}
		}
		return res;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
