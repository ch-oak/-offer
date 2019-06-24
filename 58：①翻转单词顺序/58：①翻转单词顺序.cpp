// 58：①翻转单词顺序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		ReverseCore(str, 0, str.size()-1);
		int pre = 0;
		int tail = 0;
		while (pre < str.size()) {
			if (str[pre] == ' ') {
				pre++;
				tail++;
			}
			else if (str[tail] == ' ' || tail == str.size()) {
				ReverseCore(str,pre, --tail);
				pre = ++tail;
			}
			else {
				tail++;
			}
		}
		return str;

	}
private:
	void ReverseCore(string &str, int pos1, int pos2) {
		while (pos1 < pos2) {
			swap(str[pos1++], str[pos2--]);
		}
	}
};

int main()
{
	string s{ "I am a student." };
	cout << Solution().ReverseSentence(s);
    std::cout << "Hello World!\n"; 
}
