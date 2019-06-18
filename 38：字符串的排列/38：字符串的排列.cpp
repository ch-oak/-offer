// 38：字符串的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.empty())
			return {};
		set<string> res_;//重复字母
		Permutation(str, 0, res_);
		vector<string> res(res_.begin(), res_.end());
		return res;
	}
private:
	void Permutation(string &str, int start, set<string> &res_) {
		if (start == str.size()) {
			res_.insert(str);
		}
		for (int i = start; i < str.size(); i++) {
			//递归，最后两个字母交换顺序
			swap(str[start], str[i]);
			Permutation(str, start + 1, res_);
			swap(str[start], str[i]);
		}

	}
};
int main()
{
    std::cout << "Hello World!\n"; 
}
