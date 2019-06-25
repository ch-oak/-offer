// 57：②和为s的连续正数序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum <= 2)
			return{};
		int small = 1, big = 2;
		int cur = 3;
		vector<vector<int>> res;
		while (small <= sum / 2) {
			if (cur < sum) {
				big++;
				cur += big;
			}
			else if (cur > sum) {
				cur -= small;
				small++;
			}
			else {
				vector<int> temp;
				for (int i = small; i <= big; i++)
					temp.push_back(i);
				big++;
				cur += big;
				res.push_back(temp);
			}
		}
		return res;
	}
};

int main()
{
	Solution().FindContinuousSequence(10);
    std::cout << "Hello World!\n"; 
}
