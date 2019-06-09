// 11：旋转数组的最小数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include "pch.h"
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;
//旋转数组的最小数字，两种特殊情况

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len == 0)
			return 0;
		int left = 0, right = len - 1, mid = left;//如果整体有序，直接返回mid
		while (rotateArray[left]>=rotateArray[right]) {
			if (right - left == 1) {
				mid = right;
				break;
			}
			if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]) {//left=mid=right
				int res = rotateArray[left];
				for (int i = left + 1; i <= right; i++) {
					if (rotateArray[i] < res)
						res = rotateArray[i];
				}
				return res;
			}
			mid = left + (right - left) / 2;
			if (rotateArray[mid] >= rotateArray[left])
				left = mid;
			else if (rotateArray[mid] <= rotateArray[right])
				right = mid;
		}
		return rotateArray[mid];
	}
};

int main()
{
	vector<int> rotateArray{ 3,4,5,1,2 };
	cout << Solution().minNumberInRotateArray(rotateArray);
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
