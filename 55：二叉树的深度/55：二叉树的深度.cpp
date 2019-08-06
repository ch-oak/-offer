// 55：二叉树的深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

/*
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
形成树的一条路径，最长路径的长度为树的深度。
*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//class Solution {
//public:
//	int TreeDepth(TreeNode* pRoot)
//	{
//		if (!pRoot)
//			return 0;
//		int left = TreeDepth(pRoot->left);
//		int right = TreeDepth(pRoot->right);
//
//		return left > right ? (left + 1) : (right + 1);
//	}
//};

/*输入一棵二叉树，判断该二叉树是否是平衡二叉树。*/
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth;
		return IsBalance(pRoot, depth);
	}
private:
	bool IsBalance(TreeNode* pRoot, int &Depth) {
		if (!pRoot) {
			Depth = 0;
			return true;
		}
		int left, right;
		if (IsBalance(pRoot->left, left) && IsBalance(pRoot->right, right)) {
			int diff = left - right;
			if (diff <= 1 && diff >= -1) {
				Depth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
