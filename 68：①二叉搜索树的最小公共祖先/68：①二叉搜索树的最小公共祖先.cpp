// 68：①二叉搜索树的最小公共祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
		TreeNode* cur = root, *res;
		int left = p->val, right = q->val;
		while (cur) {
			int curVal = cur->val;
			if (curVal > left&&curVal > right)//如果比左右子树都大，则在当前节点的左子树
				cur = cur->left;
			else if (curVal < left&&curVal < right)//如果比左右子树都小，则在当前的节点的右子树
				cur = cur->right;
			else
				return cur;
		}
		return cur;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

