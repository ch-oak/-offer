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
#include "limits.h"
using namespace std;


typedef unsigned long long ull;

	
#include<queue>
#include<functional>
	priority_queue<int, vector<int>, greater<int>> Q;

	int main() {
		unordered_set<int> ui{ 1,3,2,33,44,24 };
		for (auto beg = ui.begin(); beg != ui.end(); beg++) {
			cout << *beg << endl;
		}

		freopen("in.txt", "r", stdin);
		int n;
		while (cin>>n) {
			while (!Q.empty()) Q.pop();
			for (int i = 0; i < n; i++) {
				int tmp;
				scanf_s("%d", &tmp);
				Q.push(tmp);
			}
			int ans = 0;
			while (Q.size() > 1) {

				int a, b;
				a = Q.top();
				Q.pop();
				b = Q.top();
				Q.pop();
				ans += (a + b);
				Q.push(a + b);
			}
			printf("%d", ans);
		}
		return 0;
	}



//int main()
//{
//	freopen("in.txt", "r", stdin);
//	string line;
//	getline(cin,line);
//	vector<string> in;
//	stringstream ss(line);
//	string temp;
//	vector<string> res;
//	while (getline(ss, temp, ' ')) {
//		in.push_back(temp);
//	}
//	for (int i = 1; i < in.size(); i++) {
//		if (in[i] == "A") {
//			res.push_back("12");
//			res.push_back("34");
//		}
//		else if (in[i] == "B") {
//			res.push_back("AB");
//			res.push_back("CB");
//		}
//		else {
//			res.push_back(in[i]);
//		}
//			
//	}
//	int res_len = res.size() + 1;
//	string res_str;
//	while (res_len) {
//		int temp = res_len % 16;
//		if (temp < 10)
//			res_str += to_string(temp);
//		else
//			res_str += char('A' + temp - 10);
//		res_len /= 16;
//	}
//	cout << res_str << " ";
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << " ";
//}
//bool isShu(int num) {
//	for (int i = 2; i*i <= num; i++) {
//		if (num%i == 0)
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	int low, high;
//	cin >> low >> high;
//	int shi = 0, ge = 0;
//	for (int i = low; i < high - 1; i++) {
//		if (isShu(i)) {
//			cout << i << endl;
//			if (i < 10) {
//				ge += i;
//			}
//			else {
//				ge += i % 10;
//				shi += i / 10 % 10;
//			}
//		}
//	}
//	int res = ge < shi ? ge : shi;
//	cout << res;
//}

//int main()
//{
//	freopen("in.txt", "r", stdin);
//	char f;
//	cin >> f;
//	int len = 0;
//	int pos = 0;
//	while (f) {
//		int temp = f & 1;
//		len += pow(2, pos ++ )*temp;
//		f = f << 1;
//	}
//	
//	int len_copy = len - 1;
//	char in;
//	vector<string> res;
//	while (len_copy--) {
//		cin >> in;
//		string temp;
//		if ((in >= '0'&&in < '9') || (in >= 'C'&&in <= 'F') || (in >= 'c' && in <= 'f')) {
//			temp += in;
//			res.push_back(temp);
//		}
//		else if (in == 'A' || in == 'a') {
//			res.push_back("12");
//			res.push_back("34");
//		}
//		else if (in == 'B' || in == 'b') {
//			res.push_back("AB");
//			res.push_back("AB");
//		}
//	}
//	cout << res.size() + 1 << " ";
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i]<<" ";
//	}
//}

//vector<vector<int>> p;
//void permu(int start, int end, vector<int> &a) {
//	if (start == end) {
//		for (int i = 0; i < end; i++) {
//			p.push_back(a);
//		}
//	}
//	for (int i = start; i < end; i++) {
//		swap(a[start], a[i]);
//		permu(start + 1, end, a);
//		swap(a[i],a[start]);
//	}
//}
//
//int main()
//{
//	char a = 65;
//	char str = '\x0000000000000000000041';
//	cout << a << endl;
//	cout << str << endl;
//	freopen("in.txt", "r", stdin);
//	int n, m;
//	cin >> n >> m;
//	int n_ = n;
//	vector<int> f;
//	vector<int> s;
//	while (n_--) {
//		int temp;
//		cin >> temp;
//		f.push_back(temp);
//	}
//	n_ = n;
//	while (n_--) {
//		int temp;
//		cin >> temp;
//		s.push_back(temp);
//	}
//	permu(0, m, f);
//	int index, max = 0;
//
//	cout << "test" << endl;
//}

//int main()
//{
//	freopen("in.txt", "r", stdin);
//	int N, M;
//	cin >> N >> M;
//	vector<vector<int>> rect(N+2, vector<int>(M+2, 0));
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> rect[i][j];
//		}
//	}
//	int res = 0;
//	res += N * M * 2;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			int temp = rect[i][j];
//			int left = rect[i][j] - rect[i][j-1];
//			if (left < 0) left = 0;
//			int up = rect[i][j] - rect[i+1][j];
//			if (up < 0) up = 0;
//			int right = rect[i][j] - rect[i][j+1];
//			if (right < 0) right = 0;
//			int down = rect[i][j] - rect[i - 1][j];
//			if (down < 0) down = 0;
//			res += (left + right + up + down);
//		}
//	}
//	cout << res << endl;
//}

//int calc(vector<int> &tower, int left, int right, int h) {
//	if (left > right)
//		return 0;
//	if (left == right)
//		return tower[left] > h;
//	int mid = (left + right) / 2;
//	int left_res = calc(tower, left, mid, h);
//	int right_res = calc(tower, mid + 1, right, h);
//	int res = left_res + right_res;
//	if (mid + 1 < tower.size() && tower[mid + 1]> h && tower[mid] > h)
//		res--;
//	return res;
//}
//
//int calc(vector<int> &tower,int h) {
//
//	return calc(tower,0,tower.size()-1,h);
//
//}
//class Base {
//public:
//	Base() { test(); };
//	~Base() {};
//	virtual void test() { cout << "test" << endl; }
//};
//class Derived:Base {
//public:
//	Derived() { test(); cout << "end" << endl; }
//	virtual void test() { cout << "derived" << endl; }
//	~Derived(){}
//};
//
//
//
//int main()
//{
//	Base b;
//	Derived d;
//	freopen("in.txt", "r", stdin);
//
//	int N, Q, n, q;
//	cin >> N;
//	vector<int> tower(N, 0);
//	n = N;
//	int min_w = INT_MAX, max_w = INT_MIN;
//	while (n--) {
//		cin >> tower[N - n - 1];
//		min_w = min(tower[N - n - 1], min_w);
//		max_w = max(tower[N - n - 1], max_w);
//	}
//	cin >> Q;
//	vector<int> water(Q, 0);
//	q = Q;
//	while (q--)
//		cin >> water[Q - q - 1];
//	map<int,int> note;
//	for (int i = 0; i < Q; i++) {
//		if (water[i] > max_w)
//			cout << 0 << endl;
//		else if (water[i] < min_w)
//			cout << 1 << endl;
//		else {
//			if (note.find(water[i]) != note.end())
//				cout << note[water[i]] << endl;
//			else {
//				int res = calc(tower, water[i]);
//				cout << res << endl;
//				note.insert({ water[i],res });
//			}
//
//		}
//	}
//}

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