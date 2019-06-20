// 48：丑数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>

/*
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，
但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
*/
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		int *res = new int[index];
		res[0] = 1;
		int next = 1;
		int pos2 = 0;
		int pos3 = 0;
		int pos5 = 0;
		while (next < index) {
			res[next] = min(2 * res[pos2], min(3 * res[pos3], 5 * res[pos5]));
			//丑数一定是2,3,5的倍数
			while (pos2 <= next && 2 * res[pos2] <= res[next])
				pos2++;
			while (pos3 <= next && 3 * res[pos3] <= res[next])
				pos3++;
			while (pos5 <= next && 5 * res[pos5] <= res[next])
				pos5++;
			next++;
		}
		int ugly = res[index - 1];
		delete[] res;
		return ugly;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
