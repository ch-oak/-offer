// 45：把数组排成最小的数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	string str_a = to_string(a);
	string str_b = to_string(b);
	string str1 = str_a + str_b;
	string str2 = str_b + str_a;
	return str1 < str2;
}

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		sort(numbers.begin(), numbers.end(), cmp);
		string res;
		for (int i = 0; i < numbers.size(); i++)
			res += to_string(numbers[i]);
		return res;
	}
private:

};

int main()
{
	vector<int> num{ 3,32,321 };
	cout << Solution().PrintMinNumber(num);
    std::cout << "Hello World!\n"; 
}

