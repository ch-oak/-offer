// 19：正则表达式匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*(pattern + 1) == '*') {
			if (*pattern == *str || (*pattern == '.'&&*str != '\0'))//""和".*"
				return match(str + 1, pattern + 2) ||
				match(str + 1, pattern) ||
				match(str, pattern + 2);
			else
				return match(str, pattern + 2);
		}
		if (*str == *pattern || (*pattern == '.'&&*str != '\0')) {
			return match(str + 1, pattern + 1);
		}
		return false;
	}

};

int main()
{
	char str[] = "";
	char pattern[] = ".";
	cout << Solution().match(str, pattern);
    std::cout << "Hello World!\n"; 
}


