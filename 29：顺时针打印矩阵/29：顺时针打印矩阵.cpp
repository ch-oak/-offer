// 29：顺时针打印矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
		while (rows > start * 2 && cols > start * 2) {//终止条件
			printCircle(res, matrix, rows, cols, start);
			start++;
		}
		return res;
	}
private:
	void printCircle(vector<int> &res,vector<vector<int>> &matrix, int rows, int cols, int start) {
		int endRow = rows - 1 - start;
		int endCol = cols - 1 - start;
		for (int i = start; i <= endCol; i++)//第一步
			res.push_back(matrix[start][i]);


		if (endRow > start) {//第二步
			for (int i = start + 1; i <= endRow; i++)
				res.push_back(matrix[i][endCol]);
		}
		if (endRow > start&&endCol > start) {//第三步
			for (int i = endCol - 1; i >= start; --i)
				res.push_back(matrix[endRow][i]);
		}
		if (endRow > start+1&&endCol>start) {//第四步
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
