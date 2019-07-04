// 90_字节跳动_01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	vector<int> a(26);
	vector<int> b(26);
	for (int i = 0; i < 26; i++) {
		int temp;
		cin >> temp;
		a[i] = temp;
	}
	for (int i = 0; i < 26; i++) {
		int temp;
		cin >> temp;
		b[i] = temp;
	}
	vector<int> all(52);
	for (int i = 0; i < 52; i++) {
		if (i % 2)
			all[i] = b[i / 2];
		else
			all[i] = a[i / 2];
	}
	int byte = 0, dance = 0;
	
	while (true) {
		bool flag = true;
		vector<int> note(14, -1);
		for (int i = 0; i < 52; i++) {
			if (all[i] == -1)
				continue;
			else {
				if (note[all[i]] == -1)
					note[all[i]] = i;
				else {
					flag = false;
					int temp = 0;
					int start = note[all[i]];
					int end = i;
					for (int j = note[all[i]]; j <= i; j++) {
						if (all[j] != -1) {
							temp++;
							all[j] = -1;
						}
					}
					if (i % 2 == 0) {
						byte += temp;
					}
					else {
						dance += temp;
					}
					break;
				}
			}
		}
		if (flag)
			break;
	}
	string res;
	if (dance > byte)
		res = "Dance";
	else if (dance < byte)
		res = "Byte";
	else
		res = "Draw";
	cout << res;
}