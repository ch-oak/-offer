// 29：顺时针打印矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if (matrix.empty())
			return {};
		int rows = matrix.size();
		int cols = matrix[0].size();
		int start = 0;
		vector<int> res;
		while (rows > start * 2 && cols > start * 2) {//终止条件，打印一圈就是两行两列
			printCircle(res, matrix, rows, cols, start);
			start++;
		}
		return res;
	}
private:
	void printCircle(vector<int> &res,vector<vector<int>> &matrix, int rows, int cols, int start) {
		int endRow = rows - 1 - start;
		int endCol = cols - 1 - start;
		//上
		for (int i = start; i <= endCol; i++)
			res.push_back(matrix[start][i]);
		//右
		if (endRow > start) {//要想由右至少要有两行
			for (int i = start + 1; i <= endRow; i++)
				res.push_back(matrix[i][endCol]);
		}
		//下
		if (endRow > start&&endCol > start) {//要想由下至少要有两列
			for (int i = endCol - 1; i >= start; i--)
				res.push_back(matrix[endRow][i]);
		}
		//左
		if (endRow > start + 1 && endCol > start) {//要想有上至少要有3行，否则会重复
			for (int i = endRow - 1; i > start; i--)
				res.push_back(matrix[i][start]);
		}
	}
};

int main()
{
	vector<vector<int>> matrix{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	auto res = Solution().printMatrix(matrix);
    std::cout << "Hello World!\n"; 
}
