// 50：第一次只出现一次的字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置,
如果没有则返回 -1（需要区分大小写）.
*/
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


//hash表
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int* note = new int[255];
		for (int i = 0; i < 256; i++)
			note[i] = 0;
		for (int i = 0; i < str.size(); i++) {
			note[str[i]]++;
		}
		for (int i = 0; i < str.size(); i++) {
			if (note[str[i]] == 1)
				return i;
		}
		return -1;
	}
};


/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
*/
/*
与上面不同，不能进行二次遍历，所以用hash保存字符流出现的次数。
*/
class Solution
{
public:
	Solution() {
		note = new int[255];
		for (int i = 0; i < 256; i++)
			note[i] = -1;
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		index++;
		if (note[ch] == -1) {
			note[ch] = index;
		}
		else if (note[ch] >= 0) {
			note[ch] = -2;//第二次出现
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int min = INT_MAX;
		char res;
		for (int i = 0; i < 256; i++) {
			if (note[i] != -1 && note[i] != -2) {
				if (note[i] < min) {
					min = note[i];
					res = char(i);
				}
			}
		}
		if (min == INT_MAX)
			return '#';
		return res;
	}
private:
	int* note;
	int index = -1;

};
int main()
{
    std::cout << "Hello World!\n"; 
}
