// 66：构建乘积数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		vector<int> B(len), C(len), D(len);
		C[0] = 1;
		D[len - 1] = 1;
		for (int i = 1; i < len; i++) {//将乘积分为两部分，以A[i]为中心，前一部分为C[i],后一部分为D[i]
			C[i] = C[i - 1] * A[i - 1];
			D[len - i - 1] = D[len - i] * A[len - i];
		}
		for (int i = 0; i < len; i++) {
			B[i] = C[i] * D[i];
		}
		return B;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

