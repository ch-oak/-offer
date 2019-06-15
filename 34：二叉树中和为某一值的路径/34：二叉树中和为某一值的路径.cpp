// 34：二叉树中和为某一值的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
*输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
*路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*(注意: 在返回值的list中，数组长度大的数组靠前)
*/


#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (!root)
			return {};
		vector<vector<int>> res;
		vector<int> path;
		FindPath(root, expectNumber, 0, res, path);
		return res;
	}
private:
	void FindPath(TreeNode* root, int expectNumber, int curSum, vector<vector<int>> &res, vector<int> &path) {
		curSum += root->val;
		path.push_back(root->val);
		if (curSum == expectNumber && !root->left && !root->right) {
			res.push_back(path);
		}
		if (root->left)
			FindPath(root->left, expectNumber, curSum, res, path);
		if (root->right)
			FindPath(root->right, expectNumber, curSum, res, path);


	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
