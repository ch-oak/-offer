// 43：1-n整数中1出现的次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的
数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更
加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/

/*
1、取第 i 位左边的数字（高位），乘以 10 ^(i−1) ，得到基础值 a 。
2、取第 i 位数字，计算修正值： 
1、如果大于 X，则结果为 a+ 10 ^(i−1) 。
2、如果小于 X，则结果为 a 。
3、如果等 X，则取第 i 位右边（低位）数字，设为 b ，最后结果为 a+b+1 。
---------------------
作者：程序猿li
来源：CSDN
原文：https://blog.csdn.net/u013132035/article/details/80768636
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
/*找规律*/
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int cur, low, temp, high, i = 1, total = 0;
		do {
			high = n / pow(10, i);//第i位左边
			temp = n % (int)pow(10, i);
			cur = temp / pow(10, i - 1);//第i位
			low = temp % (int)pow(10, i - 1);//第i位右边
			if (cur == 1)
				total += high * pow(10, i - 1) + low + 1;
			else if (cur < 1)
				total += high * pow(10, i - 1);
			else
				total += (high + 1)*pow(10, i - 1);
			i++;
		} while (high != 0);
		return total;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

