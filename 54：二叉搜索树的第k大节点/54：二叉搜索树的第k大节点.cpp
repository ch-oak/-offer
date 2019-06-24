// 54：二叉搜索树的第k大节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		KthNodeHelp(pRoot, k);
		if (temp == NULL)
			return temp;
		TreeNode* res = temp;
		return res;
	}
public:
	TreeNode* temp = NULL;
	void KthNodeHelp(TreeNode* pRoot, int &k)
	{
		if (pRoot) {
			KthNodeHelp(pRoot->left, k);
			if (k == 1) {
				temp = pRoot;
				k--;
			}
			else
				k--;
			KthNodeHelp(pRoot->right, k);
		}
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
