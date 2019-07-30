// 31：栈的压入、弹出序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() && popV.empty())
			return true;
		stack<int> data;
		int len = popV.size();
		int i = 0;//入栈下标
		int j = 0;//出栈下标
		while(j<len) {//循环结束的条件为出栈序列走到尽头
			//往栈里压元素，直到栈顶元素与出栈序列相等
			//模拟入栈出栈过程，如果栈顶与出栈序列不同，就一直往栈里压数字
			while (data.empty() || data.top() != popV[j]) {
				if (i == len)
					break;
				data.push(pushV[i++]);
			}
			if (data.top() != popV[j])
				break;
			data.pop();//如果栈顶元素与出栈序列相同，就弹出
			j++;
		}
		if (data.empty() && j == len)//最后栈为空，并且所有元素都入过栈了
			return true;
		return false;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

