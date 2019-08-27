// 03：数组中重复的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。
*/
	bool duplicate1(int numbers[], int length, int* duplication) {//使用hash表记录所有数字
		vector<int> note(length, -1);
		bool res = false;
		for (int i = 0; i < length; i++) {
			if (note[numbers[i]] == -1)
				note[numbers[i]] = 1;
			else {
				res = true;
				*duplication = numbers[i];
				break;
			}
		}
		return res;
	}
	//数字的范围正好与下标的范围相同,比较下标和下标内存的值
	bool duplicate(int numbers[], int length, int* duplication) {
		vector<int> note(length, -1);
		bool res = false;
		for (int i = 0; i < length;i++) {
			int temp = numbers[i];
			if (temp != i) {
				if (temp == numbers[temp]) {
					res = true;
					*duplication = temp;
					break;
				}
				else
					swap(numbers[i], numbers[temp]);//每次让一个数字归位，最后会让所有数字归位
			}
		}
		return res;
	}
};

int main()
{
	int numbers[] = { 2,1,3,1,4 };
	int dup;
	Solution().duplicate(numbers, 5, &dup);
    std::cout << "Hello World!\n"; 
}
