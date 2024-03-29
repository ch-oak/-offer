﻿// 27：二叉树的镜像.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*
操作给定的二叉树，将其变换为源二叉树的镜像。
*/

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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;
		if (pRoot->left == nullptr&&pRoot->right == nullptr)
			return;
		//交换所有非叶节点的左右子节点，从上到下的交换
		swap(pRoot->left, pRoot->right);
		if (pRoot->left)
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
			
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
