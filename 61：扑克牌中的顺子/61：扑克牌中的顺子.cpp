// 61：扑克牌中的顺子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty())
			return false;
		sort(numbers.begin(), numbers.end());
		int num = 0;
		while (numbers[num] == 0)
			num++;
		int sum = 0;
		for (int i = num; i < numbers.size() - 1; i++) {
			if (numbers[i] == numbers[i + 1])
				return false;
			else
				sum += (numbers[i + 1] - numbers[i] - 1);
		}
		return sum <= num ? true : false;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

