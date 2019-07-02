// 64：求1+2+3+_+n.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class help {
public:
	help() {
		N++;
		sum += N;
	}
	static void Reset() { N = 0; sum = 0; }
	static int getSum() { return sum; }
private:
	static int N;
	static int sum;
};

int help::N = 0;
int help::sum = 0;

/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
class Solution {
public:
	int Sum_Solution(int n) {
		help::Reset();
		auto temp = new help[n];
		delete[] temp;
		temp = NULL;
		return help::getSum();
	}
private:
};

int main()
{
	std::cout << "Hello World!\n";
}
