// 13：机器人的运动范围.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking



#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格,
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），
因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

class Solution {
public:

	int movingCount(int threshold, int rows, int cols)
	{
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		return movingCountFunc(threshold, rows, cols, 0, 0, visited);

	}
private:
	int movingCountFunc(int threshold, int rows, int cols, int row, int col, vector<vector<bool>>& visited) {
		int count = 0;
		if (check(threshold, rows, cols, row, col, visited)) {//不断递归直到没有新的满足要求的点
			visited[row][col] = true;
			//从当前点往四周扩散
			count = 1 + movingCountFunc(threshold, rows, cols, row - 1, col, visited)
				+ movingCountFunc(threshold, rows, cols, row + 1, col, visited)
				+ movingCountFunc(threshold, rows, cols, row, col - 1, visited)
				+ movingCountFunc(threshold, rows, cols, row, col + 1, visited);
		}
		return count;
	}
	bool check(int threshold, int rows, int cols, int row, int col, vector<vector<bool>> visited) {
		if (row >= 0 && row < rows&&col >= 0 && col < cols && !visited[row][col]) {
			if (getDigit(row, col) <= threshold)
				return true;
		}
		return false;
	}
	int getDigit(int row, int col) {
		int res = 0;
		while (row > 0) {
			res += row % 10;
			row /= 10;
		}
		while (col > 0) {
			res += col % 10;
			col /= 10;
		}
		return res;
	}
};

int main()
{ 
	cout<<Solution().movingCount(5, 10, 10);
    std::cout << "Hello World!\n"; 
}

