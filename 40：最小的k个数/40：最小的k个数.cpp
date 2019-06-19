// 40：最小的k个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
#include "pch.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		multiset<int, std::greater<int>> res_set;
		if (k > input.size())
			return {};
		//set和multiset的底层是红黑树，插入，删除的复杂度为O(logn),查找最大值的复杂度为O(1)
		for (int i = 0; i < input.size(); i++) {
			if (res_set.size() < k)
				res_set.insert(input[i]);
			else {
				if (input[i] < *res_set.begin()) {
					res_set.erase(res_set.begin());
					res_set.insert(input[i]);
				}
			}
		}
		vector<int> res(res_set.begin(), res_set.end());
		return res;
	}
};


int main()
{
	vector<int> input{ 4,5,1,6,2,7,3,8 };
	int k = 4;
	auto res = Solution().GetLeastNumbers_Solution(input, k);
    std::cout << "Hello World!\n"; 
}
