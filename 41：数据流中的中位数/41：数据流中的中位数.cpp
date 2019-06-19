// 41：数据流中的中位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <set>

using namespace std;
/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后
位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/


/*
输入的数据依次放入大顶堆和小顶堆
该放入大顶堆时，如果比小顶堆堆顶数据大，那么将小顶堆堆顶数据置换出来放入大顶堆
小顶堆类似
*/

class Solution {
public:
	void Insert(int num)
	{
		time++;
		if (time & 1 == 1) {//奇数个
			if (max.empty())
				max.push(num);
			else {
				int temp = min.top();
				if (num > temp) {
					min.pop();
					min.push(num);
					max.push(temp);
				}
				else {
					max.push(num);
				}
			}
		}
		else {//偶数个

			int temp = max.top();
			if (num < temp) {
				max.pop();
				max.push(num);
				min.push(temp);
			}
			else {
				min.push(num);
			}
		}
	}

	double GetMedian()
	{
		if (time & 1)
			return max.top();
		else
			return (max.top() + min.top()) / 2.0;
	}
private:
	priority_queue<int, vector<int>, std::less<int>> max;//优先队列使用less，是将大的排到前面，与set使用less相反
	priority_queue<int, vector<int>, std::greater<int>> min;
	int time = 0;
};

int main()
{
	Solution s;
	vector<int> test{ 5,2,3,4,1,6,7,0,8 };
	for (int i = 0; i < test.size(); i++) {
		s.Insert(test[i]);
		cout << s.GetMedian() << endl;
	}
    std::cout << "Hello World!\n"; 
}

