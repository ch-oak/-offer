// 19：正则表达式匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>

using namespace std;

/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0'&&*pattern == '\0')//pattern+2可能会移动到尾巴上去，必须在这里返回，否则再后面+1可能会有异常
			return false;
		if (*(pattern + 1) == '*') {//模式下一个为*
			if (*pattern == *str || (*pattern == '.'&&*str != '\0'))//字符串与模式相同
				return match(str, pattern + 2) ||//消掉前面的字符
				match(str + 1, pattern + 2) ||//重复一次
				match(str + 1, pattern);//重复一次以上
			else
				return match(str, pattern + 2);//子符串与模式不同，消掉前面的字符
		}
		if (*str == *pattern || (*pattern == '.'&&*str != '\0')) {//模式下一个不为*，直接比较
			return match(str + 1, pattern + 1);
		}
		return false;
	}

};
void test(int a, int b = 7, char c = '*') {
	cout << b << endl;
	cout << "test" << endl;
}
int main()
{
	test(6, '#');
	char str[] = "";
	char pattern[] = ".";
	cout << Solution().match(str, pattern);
    std::cout << "Hello World!\n"; 
}


