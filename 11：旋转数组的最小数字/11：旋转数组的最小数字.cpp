// 11：旋转数组的最小数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include "pch.h"
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;
//旋转数组的最小数字，两种特殊情况

class Solution {
/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len == 0)
			return 0;
		int left = 0, right = len - 1;
		int mid = left;//如果整体有序，直接返回mid
		while (rotateArray[left]>=rotateArray[right]) {
			if (right - left == 1) {//到分界点了
				mid = right;
				break;
			}
			if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]) {//两边和中间的数字相同无法说笑范围
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
