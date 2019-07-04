// 14：剪绳子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/integer-break/

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*
给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n > 1并且m>1）。
每段的绳子的长度记为k[0]、k[1]、……、k[m-1]。k[0] * k[1] * …*k[m-1]可能的最大乘积是多少？
例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到最大的乘积18。
*/
//动态规划
class Solution1 {
public:
	int cut(int n) {
		//n>1，m>1,至少剪成两段
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		//n>1，m>1,至少剪成两段
		vector<int> product(n + 4, 0);
		product[0] = 0;
		product[1] = 1;
		product[2] = 2;
		product[3] = 3;
		if (n <= 3)
			return product[n];
		for (int i = 4; i <= n; i++) {
			int max = 0;
			//product[n] = max(j属于[1，n/2])(produnc[n-j]*product[j]
			for (int j = 1; j <= i / 2; j++) {//最少都要剪掉一截
				int temp = product[i - j] * product[j];
				max = temp > max ? temp : max;
			}
			product[i] = max;

		}
		return product[n];
		
	}
private:
};

/*
贪心：尽可能剪成长度为3的绳子，最后一段为4时，剪成2和2
由n>=5可以知道，2*(n-2)>n且3*(n-3)>n，要剪掉2或者3比不剪或者剪更多所得的求积更大，
又因为n>4的时候剪3更大所以，大于4就剪3，等于4就剪2
*/
class Solution {
public:
	int cut(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		int timeOf3 = n / 3;
		if (n - timeOf3 * 3 == 1)
			timeOf3--;
		int timeOf2 = (n - timeOf3 * 3) / 2;
		return pow(3, timeOf3)*pow(2, timeOf2);
	}
private:
};

int main()
{
	cout << Solution().cut(8);
    std::cout << "Hello World!\n"; 
}
