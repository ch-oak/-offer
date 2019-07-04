// 12：矩阵中的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include "pch.h"
#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以
从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
例如 
a b c e
s f c s
a d e e 
这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子
*/
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (!matrix || rows <= 0 || cols <= 0 || !str)
			return false;
		int len = 0;
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (hasPathFunc(matrix, rows, cols, i, j, str, len, visited))
					return true;
			}
		}
		return false;
	}
private:
	bool hasPathFunc(char* matrix, int rows, int cols, int row, int col, char* str, int &len, vector<vector<bool>> &visited) {
		if (str[len] == '\0')
			return true;
		if (row >= 0 && row < rows&&col >= 0 && col < cols && !visited[row][col] && matrix[row*cols + col] == str[len]) {
			len++;//row行col列元素相同
			visited[row][col] = true;
			bool temp = hasPathFunc(matrix, rows, cols, row - 1, col, str, len, visited) ||
				hasPathFunc(matrix, rows, cols, row + 1, col, str, len, visited) ||
				hasPathFunc(matrix, rows, cols, row, col - 1, str, len, visited) ||
				hasPathFunc(matrix, rows, cols, row, col + 1, str, len, visited);//或操作类似循环，当一个不满足时会进行下一个判断,或操作具有短路效果，当找到一个后直接退出
			if (!temp) {//上下左右都不走的时候说明不能走这个点
				len--;
				visited[row][col] = false;
			}
			return temp;
		}
		else
			return false;
	}
};

int main()
{
	char matrix[] = "CBCE"
					"SFCS"
		            "ADEE";
	int rows = 3;
	int cols = 4;
	char str[] = "ABCCED";
	cout << Solution().hasPath(matrix, rows, cols, str);
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
