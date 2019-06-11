// 20：表示数值的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
*A[.[B]][e|EC]或者.B[e|EC]
*①扫描由0~9组成的数位串A，A前面可以有+或者-
*②遇到小数点则扫描0~9组成的数位串B，B前面不能有+或者-
*③遇到e或者E扫描剩下的带符号数位串C,C前面可以有+或者-,e之后的串不能单独存在
*/

#include "pch.h"
#include <iostream>

class Solution {
public:
	bool isNumeric(char* string)
	{
		
		bool flag = false;
		flag = scanNum(string);
		if (*string != '\0'&&*string == '.') {
			string++;
			flag = scanUnsignedNum(string)||flag;//注意要先扫描，避免或操作短路
		}
		if (*string != '\0' && (*string == 'e' || *string == 'E')) {
			string++;
			flag = flag&&scanNum(string);


		}

		return flag&&*string=='\0';
	}
private:
	bool scanNum(char* &str) {
		if (*str != '\0' && (*str == '+' || *str == '-'))
			str++;
		return scanUnsignedNum(str);
	}
	bool scanUnsignedNum(char* &str) {
		char* before = str;
		while(*str != '\0'&&*str >= '0'&&*str <= '9')
			str++;
		return before < str;
	}

};

int main()
{
	char string[] = "123.45e+6";
	std::cout << Solution().isNumeric(string);
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
