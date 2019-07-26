// 28：对称的二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://leetcode.com/problems/symmetric-tree/




#include "pch.h"
#include <iostream>

/*
判断二叉树是否镜对称
*/
//错误的想法，左右子树均镜像对称，则二叉树镜像对称。
//正确的想法是父亲的左节点和右节点相同
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
	bool isSymmetrical(TreeNode* pRoot)
	{

		return isSymmetrical(pRoot, pRoot);
		
	}
private:
	bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot1 && !pRoot2)
			return true;
		if (!pRoot1 || !pRoot2)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);//先序遍历和对称先序遍历结果一致
	}
};

int main()
{

    std::cout << "Hello World!\n"; 
}
