// 03：数组中重复的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
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
	bool duplicate(int numbers[], int length, int* duplication) {//数字的范围正好与下标的范围相同,比较下标和下标内存的值
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
					swap(numbers[i], numbers[temp]);
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
