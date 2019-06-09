// 14：剪绳子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//动态规划
class Solution1 {
public:
	int cut(int n) {
		//n>1,至少剪成两段
		vector<int> product(n + 4, 0);
		product[0] = 0;
		product[1] = 1;
		product[2] = 2;
		product[3] = 3;
		if (n <= 3)
			return product[n];
		for (int i = 4; i <= n; i++) {
			int max = 0;
			for (int j = 1; j <= i / 2; j++) {
				int temp = product[i - j] * product[j];
				max = temp > max ? temp : max;	
			}
			product[i] = max;
			
		}
		return product[n];
		
	}
private:
};

//贪心：尽可能剪成长度为3的绳子，最后一段为4时，剪成2和2
class Solution {
public:
	int cut(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 3;
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
