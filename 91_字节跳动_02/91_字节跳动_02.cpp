// 91_字节跳动_02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int cur[13] = { 0,31,29,12,0,0,0,0,0,0,0,0,0 };
int run[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int ping[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool isRun(int year) {
	return ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	while (n--) {
		int y, m, d;
		cin >> y >> m >> d;
		int res = 0;
		if (y == 2012) {
			for (int i = 3; i < m; i++)
				res += run[i] - cur[i];
			if (m == 3)
				res += d - 12;
			else
				res += d;
		}
		else {
			//2012年剩余的天数
			for (int i = 3; i <= 12; i++) {
				res += run[i] - cur[i];
			}
			//中间年
			for (int i = 2013; i < y; i++) {
			
				if (isRun(i))
					res += 366;
				else
					res += 365;
			}
			//最后一年
			if (isRun(y)) {
				for (int i = 1; i < m; i++)
					res += run[i];
				res += d;
			}
			else {
				for (int i = 1; i < m; i++)
					res += ping[i];
				res += d;
			}
		}
		if (n)
			cout << res << endl;
		else
			cout << res;
	}
}
