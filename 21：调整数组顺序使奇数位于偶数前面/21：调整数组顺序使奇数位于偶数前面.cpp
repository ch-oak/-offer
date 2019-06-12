// 21：调整数组顺序使奇数位于偶数前面.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
	void reOrderArray(vector<int> &array) {
		if (array.empty())
			return;
		int len = array.size();
		int left = 0, right = len - 1;
		while (left<right) {
			while (left<len&&array[left] & 1) {
				left++;
			}
			while (right >= 0 && !(array[right] & 1)) {
				right--;
			}
			if (left < right)
				swap(array[left], array[right]);
		}
		return;
	}
};

//保持顺序
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.empty())
			return;
		int len = array.size();
		for (int i = 0; i < len; i++) {
			if (!(array[i] & 1)) {
				bool flag = true;
				for (int j = i; j < len; j++) {
					if (array[j] & 1) {
						flag = false;
						int temp = array[j];
						while (j > i) {
							array[j] = array[j - 1];
							j--;
						}
						array[i] = temp;
						break;
					}
					
				}
				if (flag)
					return;
			}
		}
		return;
	}
};

int main()
{
	vector<int> array{ 1,2,3,4,5,6,7 };
	Solution().reOrderArray(array);
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
