// 44：数字序列中某一位的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
数字序列0123456789101112131415...的第n位数字
*/
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int digit(int index) {
		int digits = 1;
		int nums = 0;
		int res;
		while (true) {
			if (nums == 0)
				nums += 10;
			else
				nums += pow(10, digits - 1) * 9 * digits;
			if (nums >= index) {
				res = find(index, digits, nums);
				break;
			}
			digits++;
		}
		return res;
	}
private:
	int find(int index, int digits, int nums) {
		int start = digits > 1 ? pow(10, digits - 1) : 0;
		int temp = digits > 1 ? nums - pow(10, digits - 1) * 9 * digits : 0;
		int offset = (index - temp ) / digits;
		int pos = (int)(index - temp) % digits;//
		int res = 0;
		if (pos == 0) {
			int temp = offset + start - 1;
			string str = to_string(temp);
			res = str[digits-1] - '0';
		}
		else {
			int temp = offset + start;
			string str = to_string(temp);
			res = str[pos - 1] - '0';
		}
		return res;
	}
};

int main()
{
	string str;
	for (int i = 0; i < 1000; i++) {
		str += to_string(i);
	}
	cout << str[1001] << endl;
	cout << Solution().digit(1001) << endl;
    std::cout << "Hello World!\n"; 
}

