// 90_字节跳动_01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
typedef unsigned long long ull;



struct Food{
	int p;
	int in;
	int c;
};

bool mycmp(const Food& left, const Food& right) {
	return 1.0*left.in / left.p > 1.0*right.in / right.p;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int N, T;//种类，钱
	while (cin >> N >> T) {
		int n = N;
		vector<Food> v;
		int min_p = 0;
		while (n--) {
			Food temp;
			cin >> temp.p >> temp.in >> temp.c;
			v.push_back(temp);
			min_p = min(min_p, temp.p);
		}
		sort(v.begin(), v.end(), mycmp);
		int ret = 0;
		int T_copy = T;
		for (int i = 0; i < v.size(); i++) {
			int num = 0;
			if (T >= v[i].p) num = min(T / v[i].p, v[i].c);
			else
				continue;
			T -= num * v[i].p;
			ret += num * v[i].in;
			if (T < min_p)
				break;
		}
		cout << ret << endl;
	}
}

	/*int N, times, coff;
	while (cin >> N >> times >> coff) {
		int sum = 0;
		int n = N;
		while (n--) {
			int temp;
			cin >> temp;
			sum += temp;
		}
		int speed_time = coff * 60 * times;
		int normal_time = (8 - coff) * 60;
		int total_time = speed_time + normal_time;
		if (sum > total_time) {
			cout << 0 << endl;
			continue;
		}
		else {
			if (speed_time >= sum) {
				if (sum%times == 0)
					cout << sum / times << endl;
				else
					cout << sum / times + 1 << endl;
				continue;
			}
			else {
				int res = 0;
				res += speed_time /times ;
				res += sum - speed_time;
				cout << res << endl;
				continue;
			}
		}
	}*/

	//cout << "test" << endl;
//}

	/*ull a, b,r;
	cin >> a >> b;
	if (b > a)
		swap(a, b);
	r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	cout << b;*/
	//double in;
	//cin >> in;
	//int res = 0;
	//while (in != 1) {
	//	double temp = sqrt(in);
	//	ull temp_ull = (ull)(temp);
	//	double diff = temp - temp_ull;
	//	if (diff < 0.0000001) {
	//		in = temp;
	//		res++;
	//	}
	//	else {
	//		int gap = in - temp_ull * temp_ull;
	//		in -= gap;
	//		res += gap;
	//	}
	//}
	//cout << res << endl;
	

	//return res;
//}

	/*vector<int> a(26);
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
	cout << res;*/
//}