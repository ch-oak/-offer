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
#include <string>
using namespace std;
typedef unsigned long long ull;

int calc(vector<int> &tower, int left, int right, int h) {
	if (left > right)
		return 0;
	if (left == right)
		return tower[left] > h;
	int mid = (left + right) / 2;
	int left_res = calc(tower, left, mid, h);
	int right_res = calc(tower, mid + 1, right, h);
	int res = left_res + right_res;
	if (mid + 1 < tower.size() && tower[mid + 1]> h && tower[mid] > h)
		res--;
	return res;
}

int calc(vector<int> &tower,int h) {

	return calc(tower,0,tower.size()-1,h);
}



int main()
{
	freopen("in.txt", "r", stdin);

	int N, Q, n, q;
	cin >> N;
	vector<int> tower(N, 0);
	n = N;
	int min_w = INT_MAX, max_w = INT_MIN;
	while (n--) {
		cin >> tower[N - n - 1];
		min_w = min(tower[N - n - 1], min_w);
		max_w = max(tower[N - n - 1], max_w);
	}
	cin >> Q;
	vector<int> water(Q, 0);
	q = Q;
	while (q--)
		cin >> water[Q - q - 1];
	map<int,int> note;
	for (int i = 0; i < Q; i++) {
		if (water[i] > max_w)
			cout << 0 << endl;
		else if (water[i] < min_w)
			cout << 1 << endl;
		else {
			if (note.find(water[i]) != note.end())
				cout << note[water[i]] << endl;
			else {
				int res = calc(tower, water[i]);
				cout << res << endl;
				note.insert({ water[i],res });
			}

		}
	}
}

//int main()
//{
//	freopen("in.txt", "r", stdin);
//
//	int T;
//	cin >> T;
//	while (T--) {
//		string str;
//		cin >> str;
//		int N = str.size();
//		int maxRes = 0;
//		for (int i = 0; i < N; i++) {
//			int res = 0, n = 2;
//			for (int j = i; j < N; j++) {
//				if (str[j] == 'N')
//					res++;
//				else if (n > 0) {
//					res++;
//					n--;
//				}
//				else 
//					break;
//				maxRes = max(res, maxRes);
//			}
//		}
//		cout << maxRes << endl;
//	}
//}

//int main()
//{
//	freopen("in.txt", "r", stdin);
//	
//	int T;
//	cin >> T;
//	while (T--) {
//		int m, t, m1, t1, m2, t2;
//		cin >> m >> t >> m1 >> t1 >> m2 >> t2;
//		vector<int> in(t + 1, 0);
//		vector<int> out(t + 1, 0);
//		
//		//if (T == 0)
//		//	cout << "test" << endl;
//		int flag = 1;
//		for (int i = 1; i <= t;) {
//			if (flag) {
//				for (int j = 0; j < t1; j++) {
//					if (i + j > t)
//						break;
//					in[i + j] = m1;
//				}
//				flag = 0;
//			}
//			else {
//				for (int j = 0; j < t1; j++) {
//					if (i + j > t)
//						break;
//					in[i + j] = 0;
//				}
//				flag = 1;
//			}
//			i += t1;
//		}
//
//		flag = 1;
//		for (int i = 1; i <= t;) {
//			if (flag) {
//				for (int j = 0; j < t2; j++) {
//					if (i + j > t)
//						break;
//					out[i + j] = m2;
//				}
//				flag = 0;
//			}
//			else {
//				for (int j = 0; j < t2; j++) {
//					if (i + j > t)
//						break;
//					out[i + j] = 0;
//				}
//				flag = 1;
//			}
//			i += t2;
//		}
//
//		int res = 0;
//		for (int i = 1; i <= t; i++) {
//			res += in[i] - out[i];
//			if (res <= 0)
//				res = 0;
//			if (res >= m)
//				res = m;
//		}
//		cout << res << endl;
//
//	}
//
//}

//int onesOf(int num) {
//	int res = 0;
//	while (num) {
//		res++;
//		num = num & (num - 1);
//	}
//	return res;
//}
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	int T;
//	cin >> T;
//	while (T--) {
//		int N,n;
//		cin >> N;
//		n = N;
//		vector<int> note(33, 0);
//		while (n--) {
//			int temp;
//			cin >> temp;
//			note[onesOf(temp)] = 1;
//		}
//		int res = 0;
//		for (int i = 0; i < 33; i++) {
//			if (note[i] > 0)
//				res++;
//		}
//		cout << res << endl;
//	}
//
//}



//struct Food{
//	int p;
//	int in;
//	int c;
//};
//
//bool mycmp(const Food& left, const Food& right) {
//	return 1.0*left.in / left.p > 1.0*right.in / right.p;
//}
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//
//	int N, T;//种类，钱
//	while (cin >> N >> T) {
//		int n = N;
//		vector<Food> v;
//		int min_p = 0;
//		while (n--) {
//			Food temp;
//			cin >> temp.p >> temp.in >> temp.c;
//			v.push_back(temp);
//			min_p = min(min_p, temp.p);
//		}
//		sort(v.begin(), v.end(), mycmp);
//		int ret = 0;
//		int T_copy = T;
//		for (int i = 0; i < v.size(); i++) {
//			int num = 0;
//			if (T >= v[i].p) num = min(T / v[i].p, v[i].c);
//			else
//				continue;
//			T -= num * v[i].p;
//			ret += num * v[i].in;
//			if (T < min_p)
//				break;
//		}
//		cout << ret << endl;
//	}
//}

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