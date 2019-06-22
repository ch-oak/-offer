// 53：在排序数组中查找数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


/*
统计一个数字在排序数组中出现的次数。
*/
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return -1;
		//第一个大于等于k的元素，不存在则返回尾后元素
		int start = 0, end = data.size(),mid;
		while (start < end) {
			mid = (start + end) / 2;
			if (data[mid] < k) start = mid + 1;
			else end = mid;
		}
		int pos1 = end;
		start = 0, end = data.size();
		//第一个大于k的元素，不存在则返回尾后元素
		while (start < end) {
			mid = (start + end) / 2;
			if (data[mid] <= k) start = mid + 1;
			else end = mid;
		}
		int pos2 = end;

		return pos2 - pos1;
	}
};
int main()
{
	vector<int> data{ 1,2,3,3,3,3};
	int k = 4;
	cout << Solution().GetNumberOfK(data, k) << endl;
    std::cout << "Hello World!\n"; 
}
