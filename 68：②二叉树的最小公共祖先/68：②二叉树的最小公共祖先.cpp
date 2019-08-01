// 68：②二叉树的最小公共祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//二叉搜索树的最小公共祖先
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//二叉树的最小公共祖先
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include "pch.h"
#include <iostream>

  //Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left&&right)//如果分别在左子树和有子树找到p,q的话，root一定是最低公共祖先
			return root;
		else
			return left ? left : right;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
