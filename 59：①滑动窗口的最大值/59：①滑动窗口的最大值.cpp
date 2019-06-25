// 59：①滑动窗口的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
class Solution {
public:
	/*
	给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}
	及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}
	的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
	{2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
	*/
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		if (num.empty() && size > num.size())
			return {};
		vector<int> res;
		deque<int> list;
		for (int i = 0; i < num.size(); i++) {
			if (!list.empty() && i - list.front() == size)//新插入的元素需要右移窗口
				list.pop_front();
			while (!list.empty() && num[list.back()] < num[i])//把当前窗口最大值放在队首
				list.pop_back();
			list.push_back(i);
			if (i >= size - 1)
				res.push_back(num[list.front()]);
		}
		return res;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
