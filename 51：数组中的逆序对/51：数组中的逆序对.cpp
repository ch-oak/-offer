// 51：数组中的逆序对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
即输出P%1000000007
*/

//归并思想，划分成最小因子再合并
class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.empty())
			return 0;
		vector<int> copy(data);
		int count = InversePairsCore(data, copy, 0, data.size() - 1);
		return count;
	}
private:
	int InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end) {
		if (start == end) {
			copy[start] = data[end];
			return 0;
		}

		int len = (start + end) / 2;
		int left = InversePairsCore(data, copy, start, len) % 1000000007;
		int right = InversePairsCore(data, copy, len + 1, end) % 1000000007;
		int i = len;
		int j = end;
		int count = 0;
		int indexCopy = end;
		while (i >= start && j >= len + 1) {
			if (data[i] > data[j]) {
				copy[indexCopy--] = data[i--];
				if (count > 1000000007)
					count %= 1000000007;
				count += j - len;
			}
			else
				copy[indexCopy--] = data[j--];
		}
		for (; i >= start; --i)
			copy[indexCopy--] = data[i];
		for (; j >= len + 1; --j)
			copy[indexCopy--] = data[j];
		for (int i = start; i <=end; i++)
			data[i] = copy[i];
		return (left + right + count)% 1000000007;
	}
};

int main()
{
	vector<int> data{ 1,2,3,4,5,6,7,0 };
	cout << Solution().InversePairs(data);
    std::cout << "Hello World!\n"; 
}
